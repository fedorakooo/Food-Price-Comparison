#include "product.h"

Product::Product(QString name, double* arrCost, QString file, QString category, QString subcategory) {
    this->name = name;
    this->arrCost = arrCost;
    this->category = category;
    this->file = file;
    picture = QPixmap("./image/" + file);
}

QPixmap Product::getPicture() {
    return picture;
}

QString Product::getFileName() {
    return file;
}
double* Product::getArrPrice() {
    return arrCost;
}

QString Product::getName() {
    return name;
}

double Product::getBestPrice() {
    double result = 1e20;
    for(int i = 0; i < 7; i++) {
        if(arrCost[i] > 0) {
            result = qMin(result, arrCost[i]);
        }
    }
    return result;
}
