#include <iostream>
#include <fstream>
#include <string>
#include "Benchmark.hh"
#include "ZapiszStosKolejkaLista.hh"
#include "OperacjeNaPlikach.hh"
using namespace std;

int main()
{
  long int  IloscLiczb=75000;
  double *dane= new double[IloscLiczb];
  ifstream plikwe;
  ofstream plikwyStosu,plikwyKolejki,plikwyListy;
  plikwe.open("dane.dat");
  plikwyStosu.open("wynikiStosu.dat");
  plikwyListy.open("wynikiListy.dat");
  plikwyKolejki.open("wynikiKolejki.dat");
  WczytajDaneZpliku(plikwe,IloscLiczb,dane);
  Benchmark<double> ben(8,IloscLiczb,dane);

  try{
    ben.Testuj(IloscLiczb,&ZapiszKolejnoLiczbyStosu);
    ben.ZapiszWynikiZlozonosciObliczeniowej(plikwyStosu);
    delete [] dane;
  }
  catch(string ostrzezenie)
    {cout<<ostrzezenie<<endl;}
}


