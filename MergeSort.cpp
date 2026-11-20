/**
 * @file
 * @brief Implementacja sortowania przez scalanie dla klasy MergeSort.
 * @details Zawiera operacje podziału i scalania zakresów, zarządzanie
 * pamięcią tablicy oraz jawne konkretyzacje szablonu dla wybranych typów.
 */

#include "MergeSort.h"
#include <iostream>

/**
 * @details Kopiuje oba fragmenty do tablic pomocniczych, a następnie zapisuje
 * ich elementy w kolejności rosnącej w zakresie [l, r]. Przy równych
 * wartościach wybiera element z lewej tablicy, zachowując stabilność scalania.
 * Czas działania i pamięć pomocnicza wynoszą O(r - l + 1).
 */
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

/**
 * @details Dzieli zakres na dwie części, sortuje każdą rekurencyjnie
 * i scala wyniki. Kończy rekurencję, gdy l >= r, czyli zakres zawiera
 * co najwyżej jeden element.
 */
template <typename T>
void MergeSort<T>::mergeSortA(int l, int r)
{
    if (l >= r) return;

    int m = l + (r - l) / 2;

    mergeSortA(l, m);
    mergeSortA(m + 1, r);

    merge(l, m, r);
}

/**
 * @details Dla niepustych danych przydziela własną tablicę i kopiuje
 * wszystkie elementy źródła. Dla pustych danych ustawia wewnętrzny
 * wskaźnik na nullptr, a rozmiar na 0.
 */
template <typename T>
MergeSort<T>::MergeSort(T* array, int size)
{
    if (size <= 0 || array == nullptr)
    {
        this->array = nullptr;
        this->size = 0;
        return;
    }

    this->array = new T[size];
    this->size = size;

    for (int i = 0; i < size; i++)
    {
        this->array[i] = array[i];
    }
}

/**
 * @details Usuwa wyłącznie wewnętrzną tablicę. Tablica przekazana
 * do konstruktora pozostaje własnością wywołującego.
 */
template <typename T>
MergeSort<T>::~MergeSort()
{
    delete[] this->array;
}

/**
 * @details Oddziela elementy spacjami i kończy wypisywanie znakiem nowej
 * linii. Przed listą elementów wypisuje dodatkowy znak nowej linii.
 */
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

/**
 * @details Dla co najmniej dwóch elementów uruchamia sortowanie całego
 * zakresu. Dla pustej lub jednoelementowej tablicy od razu wypisuje jej stan.
 * Dla n = size >= 2 sortowanie zajmuje O(n log n) czasu i O(n) pamięci
 * pomocniczej; głębokość rekurencji wynosi O(log n).
 */
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

    mergeSortA(0, this->size - 1);
    print_table();
}

template class MergeSort<int>;
template class MergeSort<double>;
template class MergeSort<float>;
template class MergeSort<long int>;
