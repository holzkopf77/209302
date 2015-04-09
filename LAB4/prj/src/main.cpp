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

  List<int> *lista=new List<int>;
  
  long int  IloscLiczb=30;
  //int *dane= new int[IloscLiczb];
  ifstream plikwe;
  ofstream plikwyStosu,plikwyKolejki,plikwyListy;
  plikwe.open("daneCalkowite.dat");
  plikwyStosu.open("wynikiStosu.dat");
  plikwyListy.open("wynikiListy.dat");
  plikwyKolejki.open("wynikiKolejki.dat");
  //  WczytajDaneZpliku(plikwe,IloscLiczb,dane);
  cout<<"andrzej"<<endl;
  for(int i=0;i<IloscLiczb;++i)
    {
      int a;plikwe>>a;
      lista->push_front(a);
    }
  lista->show();
  Ob(lista,IloscLiczb-1);
  cout<<endl;
  lista->show();
  /*Benchmark<int> ben(1,IloscLiczb,dane);
  try{
    ben.Testuj(IloscLiczb,&ObudowaQuickSort);
    ben.ZapiszWynikiZlozonosciObliczeniowej(plikwyStosu);
    delete [] dane;
  }
  catch(string ostrzezenie)
  {cout<<ostrzezenie<<endl;}*/
}
