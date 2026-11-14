#include "MergeSort.h"
#include <iostream>

template <typename T>
void MergeSort<T>::merge(int l, int m, int r)
{
    int sizeLeft = m - l + 1;
    int sizeRight = r - m;

    T* leftArray = new T[sizeLeft];
    T* rightArray = new T[sizeRight];

    for (int i = 0; i < sizeLeft; i++)
    {
        leftArray[i] = this->array[l + i];
    }

    for (int i = 0; i < sizeRight; i++)
    {
        rightArray[i] = this->array[m + 1 + i];
    }

    int i = 0; //pozycja w lewej
    int j = 0; //pozycja w prawej
    int k = l; //pozycja w glownej

    while (i < sizeLeft && j < sizeRight)
    {
        if (leftArray[i] <= rightArray[j])
        {
            this->array[k] = leftArray[i];
            i++;
        }
        else
        {
            this->array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < sizeLeft)
    {
        this->array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < sizeRight)
    {
        this->array[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

template <typename T>
void MergeSort<T>::mergeSort(int l, int r)
{
    if (l >= r) return;

    int m = l + (r - l) / 2;

    mergeSort(l, m);
    mergeSort(m + 1, r);

    merge(l, m, r);
}

template <typename T>
MergeSort<T>::MergeSort(T* array, int size)
{
    this->array = new T[size];
    this->size = size;

    for (int i = 0; i < size; i++)
    {
        this->array[i] = array[i];
    }
}

template <typename T>
MergeSort<T>::~MergeSort()
{
    delete[] this->array;
}

template <typename T>
void MergeSort<T>::print_table()
{
    if (this->size == 0)
    {
        std::cout << "Array is empty" << std::endl;
    }
    std::cout << std::endl;

    for (int i = 0; i < this->size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void MergeSort<T>::sort()
{
    if (this->size == 0)
    {
        print_table();
        return;
    }

    if (this->size == 1)
    {
        print_table();
        return;
    }

    mergeSort(0, this->size - 1);
    print_table();
}

template class MergeSort<int>;
template class MergeSort<double>;