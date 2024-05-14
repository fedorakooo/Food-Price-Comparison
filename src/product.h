#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QPixmap>

class Product
{
public:
    Product(QString name, double* arrCost, QString file, QString category, QString subcategory);
    double* getArrPrice();
    double getBestPrice();
    QString getName();
    QPixmap getPicture();
    QString getFileName();
private:
    QString file;
    QString name;
    QString category;
    double* arrCost;
    QPixmap picture;
};

#endif // PRODUCT_H
