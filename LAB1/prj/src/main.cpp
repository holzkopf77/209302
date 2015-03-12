#include <iostream>
#include <fstream>
#include "Benchmark.hh"
using namespace std;

void Mnoz(double *Gausowe,int size)
{
  for(long int i=0;i<size;++i)
    {
    Gausowe[i]=Gausowe[i]+2.0;
    }
}

int main()
{
  long int  IloscLiczb=1000000;
  ifstream plikwe;
  ofstream plikwy;
  plikwe.open("dane.dat");
  plikwy.open("wyniki.dat");
  Benchmark a(6,IloscLiczb);
  plikwe>>a;
  a.Testuj(6,IloscLiczb,&Mnoz);
  a.ZapiszWynikiZlozonosciObliczeniowej(plikwy,6);
}
