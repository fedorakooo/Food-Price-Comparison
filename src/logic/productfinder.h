#pragma once

#include <QString>
#include <QVector>

class ProductFinder
{
public:
    ProductFinder();
    static bool searchKMP(QString line, QString subline);
};
