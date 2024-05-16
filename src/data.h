#ifndef DATA_H
#define DATA_H

#include "product.h"
#include "stringprocessing.h"
#include <QDateTime>
#include <QRandomGenerator>
#include <QWidget>
#include <QPair>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>

class Data
{
    QSqlDatabase db;
    QSqlQuery* query;
    std::map<QString, QPair<int, int>> mapCategory = {{"Вода, напитки, соки, кофе и чай", QPair<int, int>(1, 360)},
                                                      {"Бакалея", QPair<int, int>(360, 853)},
                                                      {"Овощи и фрукты", QPair<int, int>(853, 858)},
                                                      {"Мучные кондитерские изделия", QPair<int, int>(858, 992)},
                                                      {"Сахарные кондитерские изделия", QPair<int, int>(992, 1217)},
                                                      {"Замороженные продукты", QPair<int, int>(1217, 1307)},
                                                      {"Молочные продукты, яйца", QPair<int, int>(1307, 1830)}
    };
public:
    Data();
    void setPopularProduct(QString _category, QString _subcategory);
    void setPopularProduct(QString _category, QString _subcategory, QString _substr);
    QVector<Product*> product;
    void setProduct(QString _category, QString _subcategory);
    void setProduct(QString _category, QString _subcategory, QString _substr); // поисковая строка
    QRandomGenerator* randomGenerator;
    const int ARR_SIZE_CATEGORY[7] = {8, 10, 1, 3, 5, 2, 12};
    const QString ARR_CAREGORY[7] = {"Вода, напитки, соки, кофе и чай", "Бакалея", "Овощи и фрукты", "Мучные кондитерские изделия", "Сахарные кондитерские изделия", "Замороженные продукты", "Молочные продукты, яйца"};
    QVector<QVector<QString>> ArrSubcategory;
    int getNumberNameCategory(QString category);
    const int RANGE = 20;
    const int NUMBER_CATEGORY = 7;
    const int NUMBER_SUBCATEGORY = 51;
private:
    Product* getProductQuety();
};

#endif // DATA_H
