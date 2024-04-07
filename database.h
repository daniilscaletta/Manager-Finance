#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <string>

#define DATABASE_HOSTNAME   "DataBase_Product"
#define DATABASE_NAME       "DataBase.db"
#define TABLE_SELD          "TableSeld"
#define TABLE_BOUGHT        "TableBought"
//#define TABLE_TYPE        "Type"
#define TABLE_DATE          "Date"
#define TABLE_TITLE         "Title"
#define TABLE_CATEGORY      "Category"
#define TABLE_COUNT         "Count"
#define TABLE_PRICE         "Price"
#define TABLE_SUM           "Sum"
#define TABLE_VALUE         "Value"

#define DATABASE_PATH       "C:\\Qt\\" //change personality

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    ~Database();

    void connectToDataBase();
    bool instertIntoTable(const QVariantList &data, std::string tableName);

private:
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable(std::string tableName);

    QSqlDatabase* db;
};

#endif // DATABASE_H
