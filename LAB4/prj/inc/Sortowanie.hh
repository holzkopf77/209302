#ifndef SORTOWANIE__HH
#define SORTOWANIE__HH
#include "Struktury.hh"
/*!
 * brief Funkcja sortuje tablice typu int za pomoca algorytmu quicksort
 */
void quicksort(int *tablica, int lewy, int prawy);
/*!
 * brief  Funkcja obudowuje funkcje quicksort, zeby mogla zostac wczytana przez klase Benchmark
 */
void ObudowaQuickSort(int *tablica,int rozmiar);
/*!
 *brief Funkcja sortuje Liste skladajace sie z elementow typu int za pomoca algorytmu quicksort
 */
void quicksortLista(List<int> *tablica,NodeL<int> *lewy,NodeL<int>*prawy,int l,int p);
/*!
 * brief Funkcja obudowuje funkcje quicksortLista,zeby mogla zostac wczytana przez klase Benchmark
 */
void Ob(List<int> *tablica,int rozmiar);
/*!
 * brief Sortowanie za pomoca QuickSorta z wybranem pivotem na podstawie mediany
 */
void quicksortMediana(int *tablica, int lewy, int prawy);
/*!
 * brief Funkcja obudowuje funkcje quicksortMediana,zeby mogla zostac wczytana przez klase Benchmark
 */
void ObudowaQuickSortMediana(int *tablica,int rozmiar);
/*!
 * brief Funkcja sortuje tablice skladajaca sie z elementow typu int za pomoca algorytmu Scalania
 */
void MergeSortowanie(Stack<int> *tablica,int lewy, int prawy);
/*!
 * brief Funkcja scala dwa zbiory liczb, jest funkcja skladowa MergeSortowanie
 */
void Merging(Stack<int> *tablica,int lewy, int srodkowy, int prawy);
/*!
 * brief Funkcja obudowuje funkcje MergeSortowanie,zeby mogla zostac wczytana przez klase Benchmark
 */
void ObudowaMergeSortowanie(Stack<int> *tab,int rozmiar);
#endif
