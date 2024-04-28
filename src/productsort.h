#ifndef PRODUCTSORT_H
#define PRODUCTSORT_H

#include <QVector>
#include "product.h"

class ProductSort
{
public:
    ProductSort();
    static void timsort(QVector<Product*> *array);
private:
    static void insertionSort(QVector<Product*> *array, int start_index, int end_index);
    static void merge(QVector<Product*> *array, int start_index, int mid, int end_index);
    static const int RUN = 64;
};

#endif // PRODUCTSORT_H
