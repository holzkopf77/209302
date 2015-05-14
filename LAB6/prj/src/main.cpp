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
#include "Obserwator.hh"
#include "Sortowanie.hh"
using namespace std;

int main()
{
	int a;
  ifstream daneNazw;
  ofstream wynikSortowania;
  wynikSortowania.open("wynikiSortowania.dat");
  int rozmiar=1000;
  daneNazw.open("daneCalkowite.dat");
  Obserwator<int> obserwator;
  //Benchmark<int> ben();
  try{
    List<int> lista;
	for(int i=0;i<rozmiar;++i)
	{
	daneNazw>>a;
	lista.push_front(a);
	}
    lista.dodaj(&obserwator);
    Ob(&lista,rozmiar);
    lista.powiadom();
    cout<<obserwator.ZlozonoscObliczeniowa[0][0]<<endl;
    cout<<obserwator.ZlozonoscObliczeniowa[0][1]<<endl;
    //a.WstawianieDanychZPliku(daneNazw,rozmiar);
    //a.WstawianieDanychZPliku(daneNazw,rozmiar);
    
    // ben.ZapiszWynikiZlozonosciObliczeniowej(wynikHaszowania);
  }
  catch(string ostrzezenie){cout<<ostrzezenie<<endl;}
}
