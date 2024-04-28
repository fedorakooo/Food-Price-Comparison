#ifndef STRINGPROCESSING_H
#define STRINGPROCESSING_H
#include "product.h"

class StringProcessing
{
public:
    StringProcessing();
    static bool searchKMP(QString line, QString subline);
};

#endif // STRINGPROCESSING_H
