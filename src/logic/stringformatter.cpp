#include "stringformatter.h"

StringFormatter::StringFormatter() = default;

QString StringFormatter::formatPrice(QString price) {
    bool isPointFound = false;
    int i = 0;
    while (i < price.size()) {
        if (price[i] == '.'){
            isPointFound = true;
            break;
        }
        i++;
    }
    if (isPointFound && price.size() - i <= 2) {
        return price + "0";
    }
    else if (!isPointFound) {
        return price + ".00";
    }
    return price;
}
