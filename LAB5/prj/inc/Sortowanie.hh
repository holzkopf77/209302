#ifndef SORTOWANIE__HH
#define SORTOWANIE__HH
#include "Struktury.hh"
void quicksort(int *tablica, int lewy, int prawy);
void ObudowaQuickSort(int *tablica,int rozmiar);
void quicksortLista(List<int> *tablica, int lewy,int prawy);
void Ob(List<int> *tablica,int rozmiar);
void quicksortLista2(List<int> *tablica,NodeL<int> *lewy,NodeL<int>*prawy,int l,int p);
#endif
