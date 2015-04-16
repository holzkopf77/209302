#include <iostream>
#include <fstream>
#include <string>
#include "Benchmark.hh"
#include "ZapiszStosKolejkaLista.hh"
#include "OperacjeNaPlikach.hh"
#include "Struktury.hh"
#include "Sortowanie.hh"

using namespace std;

int main()
{
  
  List<int> lista2;
  long int  IloscLiczb=30000;
  int *tab=new int[IloscLiczb];
  ifstream plikwe;
  ofstream plikwyStosu,plikwyKolejki,plikwyListy;
  plikwe.open("daneCalkowite.dat");
  plikwyStosu.open("wynikiStosu.dat");
  WczytajListe(plikwe,IloscLiczb,&lista2);

  Benchmark<List<int>> ben(1,IloscLiczb,&lista2);
  try{
    ben.Testuj(IloscLiczb,Ob);
    ben.ZapiszWynikiZlozonosciObliczeniowej(plikwyStosu);
    delete tab;
    }
  catch(string ostrzezenie)
  {cout<<ostrzezenie<<endl;}
}
