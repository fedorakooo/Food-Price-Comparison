#ifndef DATA_H
#define DATA_H

#include "product.h"
#include "stringprocessing.h"
#include <QWidget>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>

class Data
{
    QSqlDatabase db;
    QSqlQuery* query;
public:
    QVector<Product*> setAllProduct();
    Data();
    QVector<Product*> product;
    void setProduct(QString category, QString subcategory, QString substr); // поисковая строка

};

#endif // DATA_H
