#include "string_date_hash.h"

HashNode::HashNode() {}

HashNode::HashNode(const QString &key, const QDateTime &value) : key(key), value(value), next(NULL)
{
}

QString HashNode::getKey() const { return key; }

QDateTime HashNode::getValue() const { return value; }

void HashNode::setValue(QDateTime value) { HashNode::value = value; }

HashNode *HashNode::getNext() const { return next; }

void HashNode::setNext(HashNode *next) { HashNode::next = next; }

bool operator>(HashNode const &left, HashNode const &right) { return left.getValue() > right.getValue(); }

bool operator<(HashNode const &left, HashNode const &right) { return left.getValue() < right.getValue(); }

StringDateHash::StringDateHash() : table()
{
    // Populate table with null values
    for (int i = 0; i < capacity; i++)
    {
        table.push_back(NULL);
    }
}

StringDateHash::~StringDateHash()
{
    for (int i = 0; i < capacity; i++)
    {
        HashNode *entry = table[i];

        while (entry != NULL)
        {
            HashNode *prev = entry;
            entry = entry->getNext();
            delete prev;
        }

        table[i] = NULL;
    }
}

bool StringDateHash::get(const QString &key, QDateTime &value)
{
    int hashValue = hashFunc(key);

    if (hashValue >= table.size())
    {
        return false;
    }

    HashNode *entry = table[hashValue];

    while (entry != NULL)
    {
        if (entry->getKey() == key)
        {
            value = entry->getValue();
            return true;
        }

        entry = entry->getNext();
    }
    return false;
}

void StringDateHash::put(const QString &key, const QDateTime &value)
{
    int hashValue = hashFunc(key);

    if (hashValue >= table.size())
    {
        try {
            // Make table big enough for new values
            while (hashValue >= table.size())
            {
                table.push_back(NULL);
                capacity++;
            }

            table[hashValue] = new HashNode(key, value);
        } catch(const std::bad_alloc& ex) {
            QMessageBox::warning(nullptr, "Error", "Application out of memory");
            throw;
        }
    }
    else
    {
        HashNode *prev = NULL;
        HashNode *entry = table[hashValue];

        while (entry != NULL && entry->getKey() != key)
        {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == NULL)
        {
            entry = new HashNode(key, value);

            if (prev == NULL)
            {
                // insert as firt value
                table[hashValue] = entry;
            }
            else
            {
                prev->setNext(entry);
            }
        }
        else
        {
            // just update the value
            entry->setValue(value);
        }
    }
}

void StringDateHash::remove(const QString &key)
{
    int hashValue = hashFunc(key);

    if (hashValue >= table.size())
    {
        return;
    }

    HashNode *prev = NULL;
    HashNode *entry = table[hashValue];

    while (entry != NULL && entry->getKey() != key)
    {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == NULL)
    {
        return;
    }
    else
    {
        if (prev == NULL)
        {
            table[hashValue] = entry->getNext();
        }
        else
        {
            prev->setNext(entry->getNext());
        }

        delete entry;
    }
}

int StringDateHash::getSize()
{
    int size = 0;
    for (int i = 0; i < capacity; i++)
    {
        HashNode *entry = table[i];

        while (entry != NULL)
        {
            size++;
            entry = entry->getNext();
        }
    }
    return size;
}

int StringDateHash::getCapacity() const { return capacity; }

QStringList StringDateHash::getKeys()
{
    QStringList keyList;

    for (int i = 0; i < capacity; i++)
    {
        HashNode *entry = table[i];

        while (entry != NULL)
        {
            HashNode *prev = entry;
            keyList.append(prev->getKey());
            entry = entry->getNext();
        }
    }
    return keyList;
}

QStringList StringDateHash::sortByKeyAsc()
{
    QStringList keyList = StringDateHash::getKeys();
    keyList.sort();
    return keyList;
}

QStringList StringDateHash::sortByKeyDesc()
{
    QStringList keyList = StringDateHash::sortByKeyAsc();
    QStringList dscKeyList;
    for (int i = keyList.size() - 1; i >= 0; i--)
    {
        dscKeyList.append(keyList.at(i));
    }

    return dscKeyList;
}

QStringList StringDateHash::sortByDateAsc()
{
    QStringList keyList;
    const int size = StringDateHash::getSize();
    HashNode list[size];
    HashNode sortedList[size];

    int y = 0;
    for (int i = 0; i < capacity; i++)
    {
        HashNode *entry = table[i];

        while (entry != NULL)
        {
            list[y] = HashNode(entry->getKey(), entry->getValue());
            y++;
            entry = entry->getNext();
        }
    }
    mergesort(list, list + size, sortedList);

    for (int i = 0; i < size; i++)
    {
        keyList.append(sortedList[i].getKey());
    }

    return keyList;
}

QStringList StringDateHash::sortByDateDesc()
{
    QStringList keyList;
    const int size = StringDateHash::getSize();

    HashNode list[size];
    HashNode sortedList[size];

    int y = 0;
    for (int i = 0; i < capacity; i++)
    {
        HashNode *entry = table[i];

        while (entry != NULL)
        {
            list[y] = HashNode(entry->getKey(), entry->getValue());
            y++;
            entry = entry->getNext();
        }
    }
    mergesort(list, list + size, sortedList);

    for (int i = size - 1; i >= 0; i--)
    {
        keyList.append(sortedList[i].getKey());
    }

    return keyList;
}

int StringDateHash::hashFunc(const QString &key)
{
    const QByteArray hexHash = QCryptographicHash::hash((key.toUtf8()), QCryptographicHash::Sha1);

    const int intHash = qFromLittleEndian<qint8>(hexHash);

    return abs(intHash);
}

void StringDateHash::merge(HashNode *begin, HashNode *middle, HashNode *end, HashNode *res)
{
    HashNode *a = begin;
    HashNode *b = middle;
    HashNode *r = res;

    while (a < middle && b < end)
        if (*a < *b)
            *r++ = *a++;
        else
            *r++ = *b++;

    while (a < middle)
        *r++ = *a++;
    while (b < end)
        *r++ = *b++;
    while (begin < end)
        *begin++ = *res++;
}

void StringDateHash::mergesort(HashNode *begin, HashNode *end, HashNode *res)
{
    int s = end - begin;
    if (s > 1)
    {
        HashNode *middle = begin + s / 2;
        mergesort(begin, middle, res);
        mergesort(middle, end, res);
        merge(begin, middle, end, res);
    }
}
