#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Benchmark.hh"
#include "ZapiszStosKolejkaLista.hh"
#include "OperacjeNaPlikach.hh"
#include "Struktury.hh"
#include "Sortowanie.hh"

using namespace std;

int main(int argc,char *argv[])
{
  long int IloscLiczb=10;
  if(argc>1)
    IloscLiczb=strtol(argv[1],nullptr,10);
  int *tab=new int[IloscLiczb];
  ifstream plikwe;
  ofstream plikwyStosu,plikPosortowany;
  plikwe.open("DanePosortowane100.dat");
  plikwyStosu.open("wynikiStosu.dat");
  //plikPosortowany.open("DanePosortowane.dat");
  WczytajDaneZpliku(plikwe,IloscLiczb,tab);
  Benchmark<int> ben(1,IloscLiczb,tab);
  try{
    ben.Testuj(IloscLiczb,ObudowaQuickSortMediana);
    ben.ZapiszWynikiZlozonosciObliczeniowej(plikwyStosu);
    ben.ZapiszWynikiZlozonosciObliczeniowej(cout);
    /*for(int i=0;i<IloscLiczb;++i)
      plikPosortowany<<tab[i]<<endl;*/
    delete tab;
    }
  catch(string ostrzezenie)
  {cout<<ostrzezenie<<endl;}
}
