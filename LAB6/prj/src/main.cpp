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
  ofstream wynikSortowania;
  wynikHaszowania.open("wynikSortowania.dat");
  int rozmiar=100;
  daneNazw.open("daneCalkowite.dat");
  Benchmark<int> ben();
  try{
    List<int> lista;
    lista.dodaj(&ben);
    Ob(&lista,rozmiar);
    lista.powiadom();
    //a.WstawianieDanychZPliku(daneNazw,rozmiar);
    a.WstawianieDanychZPliku(daneNazw,rozmiar);
    
    // ben.ZapiszWynikiZlozonosciObliczeniowej(wynikHaszowania);
  }
  catch(string ostrzezenie){cout<<ostrzezenie<<endl;}
}
