/**
* @file
 * @brief Przykład użycia klasy MergeSort dla typów int oraz double.
 */

#include <iostream>
#include "MergeSort.h"

/**
 * @brief Uruchamia przykład sortowania dwóch tablic liczbowych.
 * @details Tworzy obiekty MergeSort dla tablic int oraz double,
 * a następnie sortuje je i wypisuje wyniki na standardowe wyjście.
 * @return 0 po poprawnym zakończeniu programu.
 */
int main() {
    int intArray[] = {38, 27, 43, 3, 9, 82, 10};
    int intSize = sizeof(intArray) / sizeof(intArray[0]); //poprawny rozmiar bo sizeof zwraca liczbe bajtow na inta czyli dla 7- 7x4 bajty(int) => size = 28!!!

    double doubleArray[] = {12.5, 4.2, 19.8, 1.1, 7.75, 0.5};
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]); //double ma 8 bajtow

    MergeSort<int> sortInt(intArray, intSize);
    MergeSort<double> sortDouble(doubleArray, doubleSize);

    std::cout << "Posortowana tablica int: ";
    sortInt.sort();

    std::cout << "Posortowana tablica double: ";
    sortDouble.sort();

    return 0;
}