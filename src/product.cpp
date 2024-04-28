#include "product.h"

Product::Product(QString name, double* arrCostProduct, QPixmap pixmap) {
    nameProduct = name;
    picture = pixmap;
    for(int i = 0; i < 7; i++) {
        this->arrCostProduct[i] = arrCostProduct[i];
    }
}

QPixmap Product::getPixmap() {
    return picture;
}

double* Product::getArrPrice() {
    return arrCostProduct;
}

QString Product::getName() {
    return nameProduct;
}

double Product::getBestPrice() {
    double result = arrCostProduct[0];
    for(int i = 0; i < 7; i++) {
        result = qMin(result, arrCostProduct[i]);
    }
    return result;
}
