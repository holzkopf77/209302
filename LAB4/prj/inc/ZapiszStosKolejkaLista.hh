#ifndef ZAPISZSTOSKOLEJKALISTA_HH
#define ZAPISZSTOSKOLEJKALISTA_HH
#include "Lista.hh"
//Funkcje powstaly po to by sprawdzic zlozonosc zapisywania danych do struktur

/*!
 *brief Funkcja sluzy do zapisywania danych na stosie utworzonym w tej funkcji
 */
void ZapiszKolejnoLiczbyStosu(double* Gausowe,int size);
/*!
 *brief Funkcja sluzy do zapisywania danych na liscie utworzonej w tej funkcji
 */
void ZapiszKolejnoLiczbyListy(double* Gausowe,int size);
/*!
 * brief Funkcja sluzy do zapisywania danych na Kolejce utworzonej w tej funkcji
 */
void ZapiszKolejnoLiczbyKolejki(double* Gausowe,int size);
/*!
 * brief Funkcja sluzy do Wczytania Listy o elementach typu int
 */
void WczytajListe(std::istream &Strm,unsigned long int IloscDanych, List<int> * dane);
#endif
