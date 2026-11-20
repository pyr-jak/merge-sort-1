/**
 * @file
 * @brief Deklaracja szablonu klasy realizującej sortowanie przez scalanie.
 */

#ifndef MERGE_SORT_MERGESORT_H
#define MERGE_SORT_MERGESORT_H


/**
 * @brief Sortuje własną kopię tablicy algorytmem sortowania przez scalanie.
 *
 * @tparam T Typ elementów, który można domyślnie konstruować i przypisywać,
 *           porównywać operatorem <= oraz wypisywać do std::ostream.
 *
 * @details Konstruktor kopiuje dane wejściowe do wewnętrznej tablicy.
 * Wywołanie sort() porządkuje tę kopię rosnąco i wypisuje jej zawartość.
 *
 * @note W pliku implementacji dostępne są jawne konkretyzacje dla typów
 * int, double, float oraz long int.
 */
template <typename T>

class MergeSort
{
private:
    T* array; ///< Własna kopia danych wejściowych lub nullptr dla pustego obiektu.
    int size; ///< Liczba elementów wewnętrznej tablicy; 0 dla pustego obiektu.

    /**
     * @brief Scala dwa sąsiadujące, posortowane fragmenty tablicy.
     * @param[in] l Indeks pierwszego elementu lewego fragmentu.
     * @param[in] m Indeks ostatniego elementu lewego fragmentu.
     * @param[in] r Indeks ostatniego elementu prawego fragmentu.
     * @pre Zachodzi 0 <= l <= m < r < size, a fragmenty [l, m]
     *      oraz [m + 1, r] są posortowane rosnąco.
     * @post Fragment [l, r] jest posortowany rosnąco.
     */
    void merge(int l, int m, int r);

    /**
     * @brief Rekurencyjnie sortuje wskazany fragment wewnętrznej tablicy.
     * @param[in] l Indeks początku zakresu, włącznie.
     * @param[in] r Indeks końca zakresu, włącznie.
     * @pre Dla l < r obowiązuje 0 <= l < r < size.
     */
    void mergeSortA(int l, int r);

    /**
     * @brief Wypisuje elementy tablicy do standardowego strumienia wyjścia.
     * @details Dla pustej tablicy wypisuje komunikat "Array is empty".
     */
    void print_table();
public:
    /**
     * @brief Tworzy obiekt przechowujący kopię podanej tablicy.
     * @param[in] array Wskaźnik do tablicy źródłowej lub nullptr.
     * @param[in] size Liczba elementów do skopiowania.
     * @pre Jeżeli array != nullptr i size > 0, tablica źródłowa zawiera
     *      co najmniej size poprawnych elementów.
     * @details Dla array == nullptr lub size <= 0 powstaje pusty obiekt.
     */
    MergeSort(T* array, int size);

    /**
     * @brief Zwalnia pamięć zajmowaną przez wewnętrzną kopię tablicy.
     */
    ~MergeSort();

    /**
     * @brief Udostępnia wewnętrzną tablicę z aktualną kolejnością elementów.
     * @return Wskaźnik do wewnętrznej tablicy lub nullptr dla pustego obiektu.
     * @note Wskaźnik należy do obiektu i pozostaje ważny do jego zniszczenia.
     * Nie należy samodzielnie zwalniać wskazywanej pamięci.
     */
    T* getArray()
    {
        return this->array;
    }
    /**
     * @brief Sortuje wewnętrzną tablicę rosnąco i wypisuje wynik.
     * @post Elementy wewnętrznej tablicy są uporządkowane rosnąco.
     */
    void sort();
};


#endif //MERGE_SORT_MERGESORT_H
