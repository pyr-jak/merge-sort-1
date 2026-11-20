//
// Created by Kuba on 14.11.2026.
//

#ifndef MERGE_SORT_MERGESORT_H
#define MERGE_SORT_MERGESORT_H


template <typename T>

class MergeSort
{
private:
    T* array;
    int size;
    void merge(int l, int m, int r);
    void mergeSortA(int l, int r);
    void print_table();
public:
    MergeSort(T* array, int size);
    ~MergeSort();
    T* getArray()
    {
        return this->array;
    }
    void sort();
};


#endif //MERGE_SORT_MERGESORT_H