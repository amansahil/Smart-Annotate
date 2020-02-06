#ifndef STRINGDATEHASH_H
#define STRINGDATEHASH_H

#include <vector>
#include <QCryptographicHash>
#include <QDateTime>
#include <QMessageBox>
#include <QString>
#include <QtEndian>
#include <QDebug>

//! A node for `StringDateHash`
class HashNode
{
public:
    HashNode();
    HashNode(const QString &key, const QDateTime &value);

    /*!
     *  Returns `key`
     */
    QString getKey() const;

    /*!
     *  Returns `value`
     */
    QDateTime getValue() const;

    /*!
     *  Sets `value`
     *  @param value
     */
    void setValue(QDateTime value);

    /*!
     *  Sets addtional value for node with key that returns same hash value
     *  @param next
     */
    void setNext(HashNode *next);

    /*!
     *  Returns next `HashNode`
     */
    HashNode *getNext() const;

    friend bool operator>(HashNode const &left, HashNode const &right);
    friend bool operator<(HashNode const &left, HashNode const &right);

private:
    QString key;
    QDateTime value;

    // next bucket with the same key
    HashNode *next;
};

//! Custom Hash table container with `QString` as key and `QDate` as value
class StringDateHash
{
public:
    StringDateHash();
    ~StringDateHash();

    /*!
     *  Returns if value exists
     *  \param key
     *  \param value
     */
    bool get(const QString &key, QDateTime &value) const;

    /*!
     *  Adds or updates an hashnode in the hash table
     *  \param key
     *  \param value
     */
    void put(const QString &key, const QDateTime &value);

    /*!
     *  Removed hashnode in the table
     *  \param key
     */
    void remove(const QString &key);

    /*!
     *  Returns total number of values stored in the hash table
     */
    int getSize() const;

    /*!
     *  Returns `capacity`
     */
    int getCapacity() const;

    /*!
     *  Returns a list of all keys
     */
    QStringList getKeys() const;

    /*!
     *  Returns a list of all key values sorted by ascending
     */
    QStringList sortByKeyAsc() const;

    /*!
     *  Returns a list of all key values sorted by descending
     */
    QStringList sortByKeyDesc() const;

    /*!
     *  Returns a list of all key values sorted by ascending order of dates
     */
    QStringList sortByDateAsc() const;

    /*!
     *  Returns a list of all key values sorted by descending order of dates
     */
    QStringList sortByDateDesc() const;

private:
    //! Container for total capacity of the table
    int capacity = 1;

    //! Container for the table
    std::vector<HashNode *> table;

    //! Hash function
    int hashFunc(const QString &key) const;

    static void merge(HashNode *begin, HashNode *middle, HashNode *end, HashNode *res);
    static void mergesort(HashNode *begin, HashNode *end, HashNode *res);

    StringDateHash(const StringDateHash &other);
    const StringDateHash &operator=(const StringDateHash &other);
};

#endif // STRINGDATEHASH_H
