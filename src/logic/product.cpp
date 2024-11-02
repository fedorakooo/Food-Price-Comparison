#include "product.h"

Product::Product() :
    file(""),
    name(""),
    category(""),
    arrCost(QVector<double>(8, -1)),
    picture(QPixmap()) {}

Product::Product(QString name, const QVector<double> arrCost, QString file, QString category, QString subcategory) :
    name(name),
    arrCost(arrCost),
    file(file),
    category(category),
    subcategory(subcategory),
    picture(QPixmap("./image/" + file)) {}

QPixmap Product::getPicture() const {
    return picture;
}

QString Product::getFileName() const {
    return file;
}

QString Product::getCategory() const {
    return category;
}
QString Product::getSubcategory() const {
    return subcategory;
}

QVector<double> Product::getArrPrice() const {
    return arrCost;
}

QString Product::getName() const {
    return name;
}

double Product::getBestPrice() const {
    double result = std::numeric_limits<double>::max();
    bool foundProduct = false;
    for (auto price : arrCost) {
        if (price >= 0) {
            foundProduct = true;
            result = qMin(result, price);
        }
    }
    return foundProduct ? result : -1;
}

bool Product::isValid() const {
    return name != "";
}
