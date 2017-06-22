#ifndef CREATEDICTIONARRY_H
#define CREATEDICTIONARRY_H

//#include "dictionarry.h"
#include "database.h"
#include "model.h"
#include <QtSql/QSqlTableModel>
#include <QModelIndex>


class CreateDictionarry
{
public:
    DataBase        *db1;
    QSqlTableModel  *model;
    Model *myModel;

public:
    CreateDictionarry();
    ~CreateDictionarry();
    CreateDictionarry(QString DictName);
    bool CreateDict(QString DictName);
};

#endif // CREATEDICTIONARRY_H
