#pragma once

#include <QPixmap>
#include <QString>
#include <QVector>

class Product {
public:
    Product();
    Product(QString name, const QVector<double> arrCost, QString file, QString category, QString subcategory);

    QVector<double> getArrPrice() const;
    double getBestPrice() const;
    QString getName() const;
    QString getCategory() const;
    QString getSubcategory() const;
    QPixmap getPicture() const;
    QString getFileName() const;
    bool isValid() const;
private:
    QString file;
    QString name;
    QString category;
    QString subcategory;
    QVector<double> arrCost;
    QPixmap picture;
};
