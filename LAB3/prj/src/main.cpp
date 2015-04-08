#include <iostream>
#include <fstream>
#include <string>
#include "Benchmark.hh"
#include "ZapiszStosKolejkaLista.hh"

using namespace std;

int main()
{
  long int  IloscLiczb=75000;
  ifstream plikwe;
  ofstream plikwyStosu,plikwyKolejki,plikwyListy;
  plikwe.open("dane.dat");
  plikwyStosu.open("wynikiStosu.dat");
  plikwyListy.open("wynikiListy.dat");
  plikwyKolejki.open("wynikiKolejki.dat");
  Benchmark<double> ben(8,IloscLiczb);
  plikwe>>ben;  

  try{
    ben.Testuj(IloscLiczb,&ZapiszKolejnoLiczbyStosu);
    ben.ZapiszWynikiZlozonosciObliczeniowej(plikwyStosu);
  }
  catch(string ostrzezenie)
    {cout<<ostrzezenie<<endl;}
}


