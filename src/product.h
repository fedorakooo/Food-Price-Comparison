#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QPixmap>

class Product
{
public:
    Product(QString name, double* arrCostProduct, QPixmap pixmap);
    double* getArrPrice();
    double getBestPrice();
    QString getName();
    QPixmap getPixmap();
private:
    QString nameProduct;
    enum Shops {
        ShopEmall,
        Shop21vek,
        ShopSosedi,
        ShopSanta,
        ShopCorona,
        ShopEvroopt,
        ShopGippo,
        ShopGreen
    };
    double arrCostProduct[7] {};
    QPixmap picture;
};

#endif // PRODUCT_H
