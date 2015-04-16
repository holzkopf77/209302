#include "TablicaAsocjacyjna.hh"
#include <string>
#include <iostream>
#include <Struktury.hh>
#include <sstream>
#include <fstream>
using namespace std;

TablicaAsocjacyjna::TablicaAsocjacyjna(unsigned long int roz):slownik(roz)
  {
    rozmiar=roz;
    if(roz>10)wzmocnienie=rozmiar/10;
    else wzmocnienie=1;
  }

void TablicaAsocjacyjna::WstawianieDoTablicy(string nazwa)
{
  unsigned int indeks=Haszowanie(nazwa);
  slownik[indeks].push_front(nazwa);
}

void TablicaAsocjacyjna::WstawianieDanychZPliku(ifstream& plikwe, int size)
{
  string nazwa;
  for (unsigned int i = 0; i < size; ++i) {
    plikwe>>nazwa;
    WstawianieDoTablicy(nazwa);
  }
}


unsigned int TablicaAsocjacyjna::Haszowanie(string nazwa)
{
  unsigned int h,i;
  
  for(i=0,h=0;i<nazwa.length();++i)
    h=h+wzmocnienie*nazwa[i]+nazwa[i];
  return h%rozmiar;
}

bool TablicaAsocjacyjna::Wyszukaj(string nazwa)
{
  unsigned int i=0;
  unsigned int indeks=Haszowanie(nazwa);
  NodeL<string> *p=slownik[indeks].head;
  if(p==nullptr)return false;
  do
    {
      if(slownik[indeks][i]==nazwa)return true;
      p=p->next;
      ++i;
    }
  while(p!=nullptr);
  
  return false;
}

ostream& TablicaAsocjacyjna::StworzDane(ostream &Strm,unsigned int rozmiarek,int IleLiter)
{
  string nazwa="";
  char litera;
  char startowy='A';
  for(unsigned long int i=0; i<rozmiarek;++i)
    {
      ostringstream ss;
      ss << i%997;
      nazwa = ss.str();
      for(int j=0;j<IleLiter-1;++j)
	{
	  litera=(startowy+i%40+2*j);
	  nazwa+=litera;
	  }
      Strm<<nazwa;
      Strm<<endl;
    }
  return Strm;
}
