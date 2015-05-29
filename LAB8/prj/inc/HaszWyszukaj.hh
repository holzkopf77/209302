#ifndef BENCHMARK_HH
#define BENCHMARK_HH
#include "TablicaAsocjacyjna.hh"
/*!
 * brief Funkcja sluzy do zapisywania do tablicy z wykorzystaniem haszowania.
 */
void ZapisywanieDoTablicy(TablicaAsocjacyjna *a, int rozmiar);
/*!
 * brief Funkcja sluzy do odnajdowania elementow w tablicy haszowanej.
 */
void WyszukiwanieWTablicy(TablicaAsocjacyjna *a,int rozmiar);
#endif
