#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H

#include <QFile>
#include <QCoreApplication>
#include <QVector>
#include <QPixmap>
#include "product.h"

class DataProcessing
{
public:
    DataProcessing();
    Product* getProduct(int number);
    int getNumberAllProduct();
    QVector<Product*> getVectorAllProduct();
private:
    QFile* file;
    QVector<Product*> vectorProduct;
    void addSetProduct();
    QString path;
    double errorArr[7] {};
    Product* errorProduct;
    QPixmap errorPicture;
};

#endif // DATAPROCESSING_H
