#ifndef STRINGPROCESSING_H
#define STRINGPROCESSING_H

#include "product.h"
#include <QDebug>

class StringProcessing
{
public:
    StringProcessing();
    static bool searchKMP(QString line, QString subline);
    static QString additionPrice(QString price);
};

#endif // STRINGPROCESSING_H
