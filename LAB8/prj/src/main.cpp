#include <iostream>
#include "Graf.hh"
#include <list>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
  int wierzcholkow=10; int krawedzi=wierzcholkow;
  if(argc==1)cout<<"Dodatkowe argumenty wywolania programu:"<<endl<<
	    "./a.out liczbaWierzcholkow liczbaDodatkowychKrawedzi"<<endl;
  if(argc>1)wierzcholkow=strtol(argv[1],nullptr,10);
  if(argc>2)krawedzi=strtol(argv[2],nullptr,10);
  Obserwator<int> obserwator;
  
  Graf<int> graf(wierzcholkow);
  graf.StworzLosowyGraf(krawedzi);
  graf.dodaj(&obserwator);

  graf.CzasZnajdowaniaDrogiBFS(0,wierzcholkow-1);
  graf.powiadom();
  obserwator.zapisz(cout);
  obserwator.clear();
  
  graf.CzasZnajdowaniaDrogiDFS(0,wierzcholkow-1);
  graf.powiadom();
  obserwator.zapisz(cout);
  obserwator.clear();
}









