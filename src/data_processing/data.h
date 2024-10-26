#ifndef DATA_H
#define DATA_H

#include "logic/product.h"
#include <QMap>
#include "logic/stringprocessing.h"
#include <QDateTime>
#include <QRandomGenerator>
#include <QPair>
#include <QSqlDatabase>
#include <QSqlQuery>

class Data
{
public:
    Data();
    void setPopularProduct(QString _category, QString _subcategory);
    QVector<Product*> product;
    void setProduct(QString _category, QString _subcategory);
    void setProduct(QString _category, QString _subcategory, QString _substr);
    QRandomGenerator* randomGenerator;
    QVector<QVector<QString>> ArrSubcategory;
    int getNumberNameCategory(QString category);
    void deleteNoProduct();
    void doProductMultiples();
    QStringList getWordList(QString category, QString subcategory);
    QVector<QStringList> wordListCategory;
    const QString ARR_CAREGORY[7] = {"Вода, напитки, соки, кофе и чай", "Бакалея", "Овощи и фрукты", "Мучные кондитерские изделия", "Сахарные кондитерские изделия", "Замороженные продукты", "Молочные продукты, яйца"};
private:
    void setWordListCategory();
    Product* getProductFromData();
    const int RANGE = 20;
    const int NUMBER_CATEGORY = 7;
    const int NUMBER_SUBCATEGORY = 51;
    const int ARR_SIZE_CATEGORY[7] = {8, 10, 1, 3, 5, 2, 12};
    const int SIZE_SET_POPULAR_PRODUCTS = 40;
    std::map<QString, QPair<int, int>> mapCategory;
    QSqlDatabase db;
    QSqlQuery* query;
};

#endif // DATA_H
