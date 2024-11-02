#pragma once

#include <QMap>
#include <QDateTime>
#include <QRandomGenerator>
#include <QPair>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "logic/product.h"

class Data {
public:
    Data();
    ~Data();

    void setProduct(const QString& category, const QString& subcategory);
    void setProduct(const QString& category, const QString& subcategory, const QString& substr);
    void setPopularProduct(QString _category, QString _subcategory);

    QVector<Product*> product;
    QRandomGenerator* randomGenerator;
    QVector<QVector<QString>> ArrSubcategory;
    QVector<QStringList> wordListCategory;

    const QString ARR_CATEGORY[7] = {
        "Вода, напитки, соки, кофе и чай",
        "Бакалея",
        "Овощи и фрукты",
        "Мучные кондитерские изделия",
        "Сахарные кондитерские изделия",
        "Замороженные продукты",
        "Молочные продукты, яйца"
    };

    void deleteNoProduct();
    void doProductMultiples();
    int getNumberNameCategory(QString category);
    QStringList getWordList(QString category, QString subcategory);

private:
    void setWordListCategory();
    void initializeDatabase();
    void createProductsTable();
    void initializeCategories();
    void loadAllProducts();
    void loadProductsByCategory(const QString& category);
    void loadProductsBySubcategory(const QString& subcategory);
    void loadProducts(const QString& substr);
    void loadProductsBySubcategory(const QString& subcategory, const QString& substr);
    void handleCategoryProducts();
    void handleSubcategoryProducts(const QString& category);
    void fetchProductsFromIds(const QSet<int>& ids);
    Product* createProductFromQuery();
    Product* getProductFromData();
    QString getRandomSubcategory(const QString& category);
    QString getRandomSubcategoryForAnyCategory();

    const int RANGE = 20;
    const int NUMBER_CATEGORY = 7;
    const int NUMBER_SUBCATEGORY = 51;
    const int ARR_SIZE_CATEGORY[7] = {8, 10, 1, 3, 5, 2, 12};
    const int SIZE_SET_POPULAR_PRODUCTS = 40;

    std::map<QString, QPair<int, int>> mapCategory;
    QSqlDatabase db;
    QSqlQuery* query;
};
