#include <gtest/gtest.h>
#include <cstdlib>
#include <ctime>
#include "MergeSort.h"

// zachowuje tablicę niezmienioną, gdy ona jest już posortowana rosnąco,
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

// potrafi posortować tablicę, która jest posortowana w odwrotnej kolejności,
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

// poprawnie sortuje losową tablicę liczb,
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

// poprawnie sortuje tablice tylko z liczbami ujemnymi,
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

// poprawnie sortuje tablice z liczbami ujemnymi i liczbami dodatnimi,
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

// obsługuje pustą tablicę bez rzucania wyjątkiem,
TEST(MergeSortTest, EmptyArray) {
    int* input = nullptr;
    int size = 0;

    EXPECT_NO_THROW({
        MergeSort<int> arrayTest(input, size);
        arrayTest.sort();
    });
}

// nie zmienia tablicy, która zawiera tylko jeden element,
TEST(MergeSortTest, SingleElement) {
    int input[] = { 42 };
    int size = 1;

    MergeSort<int> arrayTest(input, size);
    arrayTest.sort();

    EXPECT_EQ(arrayTest.getArray()[0], 42);
}

// poprawnie sortuje tablicę z duplikatami liczb,
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

// poprawnie sortuje tablice ujemną z duplikatami,
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

// poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami,
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

// poprawnie sortuje tablicę zawierającą tylko dwa elementy w kolejności rosnącej,
TEST(MergeSortTest, TwoElementsAscending) {
    int input[] = { 10, 20 };
    int size = 2;

    MergeSort<int> arrayTest(input, size);
    arrayTest.sort();

    EXPECT_EQ(arrayTest.getArray()[0], 10);
    EXPECT_EQ(arrayTest.getArray()[1], 20);
}

// poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów,
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

// poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów z liczbami ujemnymi, dodatnimi oraz duplikatami,
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