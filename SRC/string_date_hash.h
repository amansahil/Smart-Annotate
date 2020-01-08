#ifndef STRINGDATEHASH_H
#define STRINGDATEHASH_H

#include <QString>
#include <QDateTime>
#include <vector>
#include <QCryptographicHash>
#include <QtEndian>

class HashNode
{
public:
    HashNode();
    HashNode(const QString &key, const QDateTime &value);

    QString getKey() const;

    QDateTime getValue() const;

    void setValue(QDateTime value);
    void setNext(HashNode *next);

    HashNode *getNext() const;

    friend bool operator>(HashNode const &left, HashNode const &right);
    friend bool operator<(HashNode const &left, HashNode const &right);

private:
    QString key;
    QDateTime value;

    // next bucket with the same key
    HashNode *next;
};

class StringDateHash
{
public:
    StringDateHash();
    ~StringDateHash();

    bool get(const QString &key, QDateTime &value);

    void put(const QString &key, const QDateTime &value);
    void remove(const QString &key);

    int getSize();
    int getCapacity();

    QStringList getKeys();
    QStringList sortByKeyAsc();
    QStringList sortByKeyDesc();
    QStringList sortByDateAsc();
    QStringList sortByDateDesc();

private:
    int capacity = 200;

    std::vector<HashNode *> table;

    int hashFunc(const QString &key) const;

    void merge(HashNode *begin, HashNode *middle, HashNode *end, HashNode *res);
    void mergesort(HashNode *begin, HashNode *end, HashNode *res);

    StringDateHash(const StringDateHash &other);
    const StringDateHash &operator=(const StringDateHash &other);
};

#endif // STRINGDATEHASH_H
