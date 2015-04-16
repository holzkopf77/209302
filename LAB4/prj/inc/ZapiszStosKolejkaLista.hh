#ifndef ZAPISZSTOSKOLEJKALISTA_HH
#define ZAPISZSTOSKOLEJKALISTA_HH
#include "Lista.hh"
void ZapiszKolejnoLiczbyStosu(double* Gausowe,int size);
void ZapiszKolejnoLiczbyListy(double* Gausowe,int size);
void ZapiszKolejnoLiczbyKolejki(double* Gausowe,int size);
void WczytajListe(std::istream &Strm,unsigned long int IloscDanych, List<int> * dane);
#endif
