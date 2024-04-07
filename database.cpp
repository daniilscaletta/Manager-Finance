#include "database.h"

Database::Database(QObject *parent) : QObject(parent)
{

}

Database::~Database()
{

}


void Database::connectToDataBase()
{
    if (!QFile(DATABASE_PATH+DATABASE_NAME).exists()){
        this->restoreDataBase();
    }
    else{
        this->openDataBase();
    }
}

bool Database::instertIntoTable(const QVariantList &data, std::string tableName)
{
    QSqlQuery query;

    query.prepare("INSERT INTO " + tableName + " ( " TABLE_DATE ", "
                                                     TABLE_TITLE      ", "
                                                     TABLE_CATEGORY   ", "
                                                     TABLE_COUNT      ", "
                                                     TABLE_PRICE      ", "
                                                     TABLE_SUM        ", "
                                                     TABLE_VALUE      " ) "
                   "VALUES (:Date, :Title, :Category, :Count, :Price, :Sum, :Value)");

    query.bindValue(":Date",             data[0].toDate());
    query.bindValue(":Title",            data[1].toString());
    query.bindValue(":Category",         data[2].toString());
    query.bindValue(":Count",            data[3].toInt());
    query.bindValue(":Price",            data[4].toInt());
    query.bindValue(":Sum",              data[5].toInt());
    query.bindValue(":Value",            data[6].toString());

    if(!query.exec()){
            qDebug() << "error insert into " << tableName;
            qDebug() << query.lastError().text();
            return false;
        } else {
            return true;
        }
        return false;
}



bool Database::openDataBase()
{
    db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase("QSQLITE");
    db->setHostName(DATABASE_HOSTNAME);
    db->setDatabaseName(DATABASE_PATH+DATABASE_NAME);
    if(db->open())
       return true;
    else
        return false;
}

bool Database::restoreDataBase()
{
    if (this->openDataBase())
    {
        if(!this->createTable(TABLE_BOUGHT))
            return false;
        else
            return true;
    }
    else
    {
        QDebug() << "Не удалось восстановить DB";
        return false;
    }
    return false;
}

void Database::closeDataBase()
{
    db->close();
}

bool Database::createTable(std::string tableName)
{
    QSqlQuery query;
    std::string word;
    word = "H" + tableName + "dcdsv"
           "E"
           "l"
           "l"
           "o";
    std::string query_exec = "CREATE TABLE " + tableName + " ("
                                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                          TABLE_DATE          " DATE               NOT NULL,"
                                          TABLE_TITLE         " VARCHAR(255)       NOT NULL,"
                                          TABLE_CATEGORY      " VARCHAR(255)       NOT NULL,"
                                          TABLE_COUNT         " INTEGER            NOT NULL,"
                                          TABLE_PRICE         " INTEGER            NOT NULL,"
                                          TABLE_SUM           " INTEGER            NOT NULL,"
                                          TABLE_VALUE         " VARCHAR(255)       NOT NULL"
                                          " )";

    if (!query.exec(query_exec))
    {
        qDebug() << "DataBase: error of create " << // TABLE //;
        qDebug() << query.lastError().text();
        return false;
    }
    else
        return true;

    return false;
}





