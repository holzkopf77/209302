#include <iostream>
#include <fstream>
#include <string>
#include "Benchmark.hh"
#include "ZapiszStosKolejkaLista.hh"
#include "OperacjeNaPlikach.hh"
#include "Struktury.hh"
#include "TablicaAsocjacyjna.hh"
#include "HaszWyszukaj.hh"
#include <vector>
using namespace std;

int main()
{
  ifstream daneNazw;
  ofstream wynikHaszowania;
  wynikHaszowania.open("wynikHaszowania.dat");
  int rozmiar=100;
  daneNazw.open("daneNazwy.dat");
  try{
    TablicaAsocjacyjna a(rozmiar);
    //a.WstawianieDanychZPliku(daneNazw,rozmiar);
    Benchmark<TablicaAsocjacyjna> ben(1,rozmiar,&a);
    a.WstawianieDanychZPliku(daneNazw,rozmiar);
    ben.Testuj(rozmiar,wypuszek);
    ben.ZapiszWynikiZlozonosciObliczeniowej(wynikHaszowania);
  }
  catch(string ostrzezenie){cout<<ostrzezenie<<endl;}
}
