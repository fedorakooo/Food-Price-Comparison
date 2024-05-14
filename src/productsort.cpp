#include "productsort.h"
ProductSort::ProductSort() {

}

void ProductSort::insertionSort(QVector<Product*> *array, int start_index, int end_index)
{
    Product* temp;
    for (int i = start_index + 1; i <= end_index; i++)
    {
        temp = array->at(i);
        int j = i - 1;

        while(j >= 0 && temp->getBestPrice() < array->at(j)->getBestPrice())
        {
            (*array)[j+1] = array->at(j);
            j--;
        }
        (*array)[j+1] = temp;
    }
}

void ProductSort::merge(QVector<Product*> *array, int start_index, int mid, int end_index)
{
    int left_size = mid - start_index + 1;
    int right_size = end_index - mid;
    QVector<Product*> left_array(left_size);
    QVector<Product*> right_array(right_size);

    for (int i = 0; i < left_size; i++)
    {
        left_array[i] = array->at(start_index + i);
    }

    for (int j = 0; j < right_size; j++)
    {
        right_array[j] = array->at(mid + 1 + j);
    }

    int i = 0;
    int j = 0;
    int k = start_index;

    for (; i < left_size && j < right_size; k++)
    {
        if(left_array[i] <= right_array[j])
        {
            (*array)[k] = left_array[i];
            i++;
        }
        else
        {
            (*array)[k] = right_array[j];
            j++;
        }
    }
    for (; i<left_size ;i++ , k++)
    {
        (*array)[k] = left_array[i];
    }
    for (; j < right_size; j++ , k++)
    {
        (*array)[k] = right_array[j];
    }
}

void ProductSort::timsort(QVector<Product*> *array)
{

    while(array->back()->getBestPrice() == 0) {
        array->pop_back();
    }

    for (int i = 0; i < (*array).size(); i = i + RUN)
    {
        insertionSort(array, i, qMin((i+RUN-1), ((array)->size() - 1)));
    }

    for (int n = RUN; n < (*array).size(); n *= 2)
    {
        for (int start_index = 0; start_index < array->size(); start_index += 2*n)
        {
            int mid = start_index + n - 1;
            int end_index = qMin((start_index + 2*n - 1),((*array).size()-1));

            if(mid < end_index)
            {
                merge(array, start_index, mid, end_index);
            }
        }
    }
}
