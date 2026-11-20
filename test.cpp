/**
 * @file
 * @brief Testy jednostkowe klasy MergeSort wykorzystujące Google Test.
 * @details Obejmują różne kolejności danych, liczby ujemne, duplikaty,
 * tablice o większych rozmiarach oraz tablice puste i jednoelementowe.
 */

#include <gtest/gtest.h>
#include <cstdlib>
#include <ctime>
#include "MergeSort.h"

/**
 * @brief Sprawdza sortowanie tablicy już uporządkowanej rosnąco.
 * @test Wynik sortowania sześciu rosnących liczb jest zgodny
 * z oczekiwaną tablicą o tej samej kolejności elementów.
 */
TEST(MergeSortTest, SortedAscending) {
    int input[] = { 1, 2, 3, 4, 5, 6 };
    int expected[] = { 1, 2, 3, 4, 5, 6 };
    int size = 6;

    MergeSort<int> arrayTest(input, size);
    arrayTest.sort();

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(arrayTest.getArray()[i], expected[i]);
    }
}

/**
 * @brief Sprawdza sortowanie tablicy uporządkowanej malejąco.
 * @test Siedem liczb podanych w odwrotnej kolejności zostaje
 * uporządkowanych rosnąco zgodnie z tablicą oczekiwaną.
 */
TEST(MergeSortTest, ReverseSorted) {
    int input[] = { 9, 7, 5, 3, 1, -2, -6 };
    int expected[] = { -6 ,-2, 1, 3, 5, 7, 9 };
    int size = 7;

    MergeSort<int> arrayTest(input, size);
    arrayTest.sort();

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(arrayTest.getArray()[i], expected[i]);
    }
}

/**
 * @brief Sprawdza sortowanie losowej tablicy liczb nieujemnych.
 * @test Po posortowaniu 15 liczb z zakresu [0, 999] każdy element
 * jest mniejszy lub równy elementowi następującemu po nim.
 */
TEST(MergeSortTest, RandomArray) {
    srand(time(nullptr));
    const int size = 15; //musi byc const bo w visual studio sie wywali
    int input[size];

    for (int i = 0; i < size; i++) {
        input[i] = rand() % 1000;
    }

    MergeSort<int> arrayTest(input, size);
    arrayTest.sort();

    for (int i = 0; i < size - 1; i++) {
        EXPECT_LE(arrayTest.getArray()[i], arrayTest.getArray()[i + 1]);
    }
}

/**
 * @brief Sprawdza sortowanie tablicy zawierającej wyłącznie liczby ujemne.
 * @test Wynik sortowania pięciu liczb ujemnych jest zgodny
 * z oczekiwaną kolejnością rosnącą.
 */
TEST(MergeSortTest, OnlyNegative) {
    int input[] = { -5, -1, -50, -12, -3 };
    int expected[] = { -50, -12, -5, -3, -1 };
    int size = 5;

    MergeSort<int> arrayTest(input, size);
    arrayTest.sort();

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(arrayTest.getArray()[i], expected[i]);
    }
}

/**
 * @brief Sprawdza sortowanie liczb ujemnych, dodatnich oraz zera.
 * @test Wynik sortowania siedmiu liczb o różnych znakach jest zgodny
 * z oczekiwaną kolejnością rosnącą.
 */
TEST(MergeSortTest, NegativeAndPositive) {
    int input[] = { -10, 5, 0, -3, 8, -1, 2 };
    int expected[] = { -10, -3, -1, 0, 2, 5, 8 };
    int size = 7;

    MergeSort<int> arrayTest(input, size);
    arrayTest.sort();

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(arrayTest.getArray()[i], expected[i]);
    }
}

/**
 * @brief Sprawdza obsługę pustej tablicy.
 * @test Utworzenie obiektu dla nullptr i rozmiaru 0 oraz wywołanie
 * sort() nie zgłaszają wyjątku.
 */
TEST(MergeSortTest, EmptyArray) {
    int* input = nullptr;
    int size = 0;

    EXPECT_NO_THROW({
        MergeSort<int> arrayTest(input, size);
        arrayTest.sort();
    });
}

/**
 * @brief Sprawdza sortowanie tablicy jednoelementowej.
 * @test Po sortowaniu jedyny element wewnętrznej tablicy
 * zachowuje wartość 42.
 */
TEST(MergeSortTest, SingleElement) {
    int input[] = { 42 };
    int size = 1;

    MergeSort<int> arrayTest(input, size);
    arrayTest.sort();

    EXPECT_EQ(arrayTest.getArray()[0], 42);
}

/**
 * @brief Sprawdza sortowanie dodatnich liczb z duplikatami.
 * @test Wynik zawiera wszystkie siedem wartości, w tym powtórzenia,
 * w kolejności zgodnej z tablicą oczekiwaną.
 */
TEST(MergeSortTest, Duplicates) {
    int input[] = { 5, 2, 8, 2, 5, 1, 8 };
    int expected[] = { 1, 2, 2, 5, 5, 8, 8 };
    int size = 7;

    MergeSort<int> arrayTest(input, size);
    arrayTest.sort();

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(arrayTest.getArray()[i], expected[i]);
    }
}

/**
 * @brief Sprawdza sortowanie ujemnych liczb z duplikatami.
 * @test Wynik zawiera wszystkie sześć wartości, w tym powtórzenia,
 * w kolejności zgodnej z tablicą oczekiwaną.
 */
TEST(MergeSortTest, NegativeArrayDuplicates) {
    int input[] = { -4, -1, -4, -9, -1, -2 };
    int expected[] = { -9, -4, -4, -2, -1, -1 };
    int size = 6;

    MergeSort<int> arrayTest(input, size);
    arrayTest.sort();

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(arrayTest.getArray()[i], expected[i]);
    }
}

/**
 * @brief Sprawdza sortowanie danych o różnych znakach z duplikatami.
 * @test Osiem wartości, obejmujących liczby ujemne, dodatnie i zera,
 * zostaje uporządkowanych zgodnie z tablicą oczekiwaną.
 */
TEST(MergeSortTest, MixedNumbersDuplicates) {
    int input[] = { 3, -2, 0, 3, -5, 0, -2, 7 };
    int expected[] = { -5, -2, -2, 0, 0, 3, 3, 7 };
    int size = 8;

    MergeSort<int> arrayTest(input, size);
    arrayTest.sort();

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(arrayTest.getArray()[i], expected[i]);
    }
}

/**
 * @brief Sprawdza sortowanie dwóch elementów podanych rosnąco.
 * @test Po sortowaniu elementy mają kolejno wartości 10 oraz 20.
 */
TEST(MergeSortTest, TwoElementsAscending) {
    int input[] = { 10, 20 };
    int size = 2;

    MergeSort<int> arrayTest(input, size);
    arrayTest.sort();

    EXPECT_EQ(arrayTest.getArray()[0], 10);
    EXPECT_EQ(arrayTest.getArray()[1], 20);
}

/**
 * @brief Sprawdza sortowanie tablicy zawierającej ponad 100 elementów.
 * @test Po posortowaniu 120 losowych liczb z zakresu [0, 9999]
 * każda para sąsiednich elementów spełnia warunek kolejności rosnącej.
 */
TEST(MergeSortTest, Over100Elements) {
    srand(time(nullptr));
    const int size = 120; //musi byc const bo w visual studio sie wywali
    int input[size];

    for (int i = 0; i < size; i++) {
        input[i] = rand() % 10000;
    }

    MergeSort<int> arrayTest(input, size);
    arrayTest.sort();

    for (int i = 0; i < size - 1; i++) {
        EXPECT_LE(arrayTest.getArray()[i], arrayTest.getArray()[i + 1]);
    }
}

/**
 * @brief Sprawdza sortowanie dużej tablicy z powtarzającymi się wartościami.
 * @test Po posortowaniu 200 losowych liczb z zakresu [-25, 25]
 * każda para sąsiednich elementów spełnia warunek kolejności rosnącej.
 */
TEST(MergeSortTest, LargeMixedArrayDuplicates) {
    srand(time(nullptr));
    const int size = 200; //musi byc const bo w visual studio sie wywali
    int input[size];

    for (int i = 0; i < size; i++) {
        input[i] = (rand() % 51) - 25;
    }

    MergeSort<int> arrayTest(input, size);
    arrayTest.sort();

    for (int i = 0; i < size - 1; i++) {
        EXPECT_LE(arrayTest.getArray()[i], arrayTest.getArray()[i + 1]);
    }
}
