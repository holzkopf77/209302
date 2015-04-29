#include <fstream>
#include <string>
#include "HaszWyszukaj.hh"

using namespace  std;

/*!
 * Funkcja sluzy do zapisywania do tablicy z wykorzystaniem haszowania.
 * \param[] a - wskaznik na klase TablicaAsocjacyjna
 * \param[] rozmiar - jak wiele elementow ma byc wstawionych
 */
void ZapisywanieDoTablicy(TablicaAsocjacyjna *a, int rozmiar)
{
  ifstream daneNazw;
  daneNazw.open("daneNazwy.dat");
  a->WstawianieDanychZPliku(daneNazw,rozmiar);
}

/*!
 * Funkcja sluzy do odnajdowania elementow w tablicy haszowanej.
 * \param[] a - wskaznik na klase TablicaAsocjacyjna
 * \param[] rozmiar - jak wiele elementow ma byc wyszukanych
 */
void WyszukiwanieWTablicy(TablicaAsocjacyjna *a,int rozmiar)
{
  ifstream daneNazw;
  daneNazw.open("daneNazwy.dat");
  string temp;
  for (int i = 0; i < rozmiar; ++i) {
    daneNazw>>temp;
    a->Wyszukaj(temp);
  }
}
