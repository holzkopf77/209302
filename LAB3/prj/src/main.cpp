#include <iostream>
#include <fstream>
#include "Benchmark.hh"
#include "Stack.hh"
#include "Lista.hh"
#include "Kolejka.hh"
using namespace std;
void ZapiszKolejnoLiczbyStosu(double* Gausowe,int size);
void ZapiszKolejnoLiczbyListy(double* Gausowe,int size);
void ZapiszKolejnoLiczbyKolejki(double* Gausowe,int size);

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


void ZapiszKolejnoLiczbyStosu(double* Gausowe,int size)
{
  Stack<double> stos(1);
  for(long int i=0;i<size;++i)
    stos.push(Gausowe[i]);
}

void ZapiszKolejnoLiczbyListy(double* Gausowe,int size)
{
  List<double> lista;
  for(long int i=0;i<size;++i)
    lista.push_back(Gausowe[i]);
}

void ZapiszKolejnoLiczbyKolejki(double* Gausowe,int size)
{
  Kolejka<double> kolejeczka;
  for(long int i=0;i<size;++i)
    kolejeczka.push_front(Gausowe[i]);
}

