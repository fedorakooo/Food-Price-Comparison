#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H
#include <QFile>
#include <QCoreApplication>
#include <QVector>
#include "product.h"

class DataProcessing
{
public:
    DataProcessing();
    Product getProduct(int number);
private:
    QFile* file;
    QVector<Product> vectorProduct;
    void addSetProduct();
};

#endif // DATAPROCESSING_H
