#include "MergeSort.h"
#include <iostream>

template <typename T>
void MergeSort<T>::merge(int l, int m, int r)
{

}

template <typename T>
void MergeSort<T>::mergeSort(int l, int r)
{

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
    delete[] array;
}

template <typename T>
void MergeSort<T>::print_table()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}

template <typename T>
void MergeSort<T>::sort()
{

}

template class MergeSort<int>;
template class MergeSort<double>;