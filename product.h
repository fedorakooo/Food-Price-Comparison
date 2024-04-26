#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>

class Product
{
public:
    Product(QString name, double* arrCostProduct);
    double* getArrPrice();
    double getBestPrice();
    QString getName();
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
};

#endif // PRODUCT_H
