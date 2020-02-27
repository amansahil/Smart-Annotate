#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestStringDateHash

#include "../SRC/string_date_hash.h"

#include <boost/test/included/unit_test.hpp>

QDateTime dateTime1(QDate(2019, 8, 3), QTime(23, 0, 0));
QDateTime dateTime2(QDate(2018, 2, 2), QTime(12, 30, 0));
QDateTime dateTime3(QDate(2017, 6, 7), QTime(1, 10, 0));
QDateTime dateTime4(QDate(2017, 5, 7), QTime(1, 10, 0));
QDateTime dateTime5(QDate(2017, 5, 7), QTime(0, 10, 0));

QString string1("Hello");
QString string2("Goodbye");
QString string3("Apple");
QString string4("Zebra");
QString string5("Camera");

std::ostream& operator<<(std::ostream &outputStream, const QDateTime &dateTime)
{
    outputStream << dateTime.toString().toStdString();

    return outputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const QStringList &stringList)
{
    outputStream << '{';
    for (auto &key: stringList)
    {
        outputStream << ' ';
        outputStream << key.toStdString();
        outputStream << ' ';
    }
    outputStream << '}';
    return outputStream;
}

BOOST_AUTO_TEST_CASE( TestGetTrue )
{
   StringDateHash testGet;

   testGet.put(string1, dateTime1);
   testGet.put(string2, dateTime2);
   testGet.put(string3, dateTime3);

   QDateTime getDateTime1;
   QDateTime getDateTime2;
   QDateTime getDateTime3;

   bool get1 = testGet.get(string1, getDateTime1);
   bool get2 = testGet.get(string2, getDateTime2);
   bool get3 = testGet.get(string3, getDateTime3);

   BOOST_CHECK( get1 );
   BOOST_CHECK( get2 );
   BOOST_CHECK( get3 );

   BOOST_CHECK_EQUAL( dateTime1, getDateTime1 );
   BOOST_CHECK_EQUAL( dateTime2, getDateTime2 );
   BOOST_CHECK_EQUAL( dateTime3, getDateTime3 );
}

BOOST_AUTO_TEST_CASE( TestGetFalse )
{
   StringDateHash testGet;

   testGet.put(string1, dateTime1);

   QDateTime getDateTime1;

   bool get1 = testGet.get(string2, getDateTime1);

   BOOST_CHECK( !get1 );
}

BOOST_AUTO_TEST_CASE( TestGetEmptyFalse )
{
   StringDateHash testGet;

   QDateTime getDateTime1;

   bool get1 = testGet.get(string1, getDateTime1);

   BOOST_CHECK( !get1 );
}

BOOST_AUTO_TEST_CASE ( TestPut )
{
    StringDateHash testPut;

    testPut.put(string1, dateTime1);
    testPut.put(string2, dateTime2);
    testPut.put(string2, dateTime3);

    QDateTime getDateTime1;
    QDateTime getDateTime2;

    testPut.get(string1, getDateTime1);
    testPut.get(string2, getDateTime2);


    BOOST_CHECK_EQUAL( dateTime1, getDateTime1 );
    BOOST_CHECK_EQUAL( dateTime3, getDateTime2 );
}

BOOST_AUTO_TEST_CASE ( TestRemove )
{
    StringDateHash testRemove;

    testRemove.put(string1, dateTime1);
    testRemove.put(string2, dateTime2);
    testRemove.put(string3, dateTime3);

    QDateTime getDateTime1;
    QDateTime getDateTime2;
    QDateTime getDateTime3;

    testRemove.remove(string2);
    testRemove.remove(string4);

    bool get1 = testRemove.get(string1, getDateTime1);
    bool get2 = testRemove.get(string2, getDateTime2);
    bool get3 = testRemove.get(string3, getDateTime3);

    BOOST_CHECK( get1 );
    BOOST_CHECK( !get2 );
    BOOST_CHECK( get3 );
}


BOOST_AUTO_TEST_CASE ( TestGetSize )
{
    StringDateHash testgetSize;

    testgetSize.put(string1, dateTime1);
    testgetSize.put(string2, dateTime2);
    testgetSize.put(string3, dateTime3);

    BOOST_CHECK_EQUAL( testgetSize.getSize(), 3 );
}

BOOST_AUTO_TEST_CASE ( TestGetSizePut )
{
    StringDateHash testgetSize;

    testgetSize.put(string1, dateTime1);
    testgetSize.put(string2, dateTime2);
    testgetSize.put(string2, dateTime3);

    BOOST_CHECK_EQUAL( testgetSize.getSize(), 2 );
}

BOOST_AUTO_TEST_CASE ( TestGetSizeRemove )
{
    StringDateHash testgetSize;

    testgetSize.put(string1, dateTime1);
    testgetSize.put(string2, dateTime2);
    testgetSize.put(string3, dateTime3);

    testgetSize.remove(string2);

    BOOST_CHECK_EQUAL( testgetSize.getSize(), 2 );
}


BOOST_AUTO_TEST_CASE ( TestCollision )
{
    StringDateHash testCollision;

    testCollision.put(string1 , dateTime1);
    testCollision.put(string2 , dateTime2);
    testCollision.put(string3 , dateTime3);

    BOOST_CHECK( testCollision.getCapacity() >= 1 );
}

BOOST_AUTO_TEST_CASE ( TestGetKeys )
{
    StringDateHash testGetKeys;

    testGetKeys.put(string1, dateTime1);
    testGetKeys.put(string2, dateTime2);
    testGetKeys.put(string3, dateTime3);

    QStringList getKeysList = { string1, string3, string2 };

    BOOST_CHECK_EQUAL( testGetKeys.getKeys(), getKeysList );
}

BOOST_AUTO_TEST_CASE ( TestSortKeyAsc )
{
    StringDateHash testSort;

    testSort.put(string1, dateTime1);
    testSort.put(string2, dateTime2);
    testSort.put(string3, dateTime3);
    testSort.put(string4, dateTime4);
    testSort.put(string5, dateTime5);

    QStringList sortedList = { string3, string5, string2, string1, string4 };

    BOOST_CHECK_EQUAL( testSort.sortByKeyAsc(), sortedList );
}

BOOST_AUTO_TEST_CASE ( TestSortKeyDesc )
{
    StringDateHash testSort;

    testSort.put(string1, dateTime1);
    testSort.put(string2, dateTime2);
    testSort.put(string3, dateTime3);
    testSort.put(string4, dateTime4);
    testSort.put(string5, dateTime5);

    QStringList sortedList = { string4, string1, string2, string5, string3 };

    BOOST_CHECK_EQUAL( testSort.sortByKeyDesc(), sortedList );
}

BOOST_AUTO_TEST_CASE ( TestSortDateAsc )
{
    StringDateHash testSort;

    testSort.put(string1, dateTime1);
    testSort.put(string2, dateTime2);
    testSort.put(string3, dateTime3);
    testSort.put(string4, dateTime4);
    testSort.put(string5, dateTime5);

    QStringList sortedList = { string5, string4, string3, string2, string1 };

    BOOST_CHECK_EQUAL( testSort.sortByDateAsc(), sortedList );
}

BOOST_AUTO_TEST_CASE ( TestSortDateDesc )
{
    StringDateHash testSort;

    testSort.put(string1, dateTime1);
    testSort.put(string2, dateTime2);
    testSort.put(string3, dateTime3);
    testSort.put(string4, dateTime4);
    testSort.put(string5, dateTime5);

    QStringList sortedList = { string1, string2, string3, string4, string5 };

    BOOST_CHECK_EQUAL( testSort.sortByDateDesc(), sortedList );
}
