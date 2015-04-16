#include <fstream>
#include <string>
#include "HaszWyszukaj.hh"

using namespace  std;

void ZapisywanieDoTablicy(TablicaAsocjacyjna *a, int rozmiar)
{
  ifstream daneNazw;
  daneNazw.open("daneNazwy.dat");
  a->WstawianieDanychZPliku(daneNazw,rozmiar);
}

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
