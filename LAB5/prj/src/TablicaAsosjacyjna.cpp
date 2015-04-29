#include "TablicaAsocjacyjna.hh"
#include <string>
#include <iostream>
#include <Struktury.hh>
#include <sstream>
#include <fstream>
using namespace std;

/*!
 * Konstruktor parametryczny klasy TablicaAsocjacyjna
 * \param[] roz - typ int, decyduje o rozmiarze slownika i wzmocnienia
 */
TablicaAsocjacyjna::TablicaAsocjacyjna(unsigned long int roz):slownik(roz)
  {
    rozmiar=roz;
    if(roz>10)wzmocnienie=rozmiar/10;
    else wzmocnienie=1;
  }

/*!
 * Funkcja wyszukujaca dany string w slowniku z wykorzystaniem haszowania
 * \param[] nazwa - nazwa stringu, ktory bedzie haszowany i umieszczony
 * w slowniku
 */
void TablicaAsocjacyjna::WstawianieDoTablicy(string nazwa)
{
  unsigned int indeks=Haszowanie(nazwa);
  slownik[indeks].push_front(nazwa);
}

/*!
 * Funkcja wstawia dane z pliku do slownika z wykorzystaniem haszowania
 * \param[] plikwe - referencja do strumienia wejsciowego
 * \param[] size - typ int, ilosc liczb wczytanych z pliku do slownika
 */
void TablicaAsocjacyjna::WstawianieDanychZPliku(ifstream& plikwe, int size)
{
  string nazwa;
  for (unsigned int i = 0; i < size; ++i) {
    plikwe>>nazwa;
    WstawianieDoTablicy(nazwa);
  }
}

/*!
 *  Funkcja haszujaca dany string
 * \param[] nazwa - string z ktorego zostanie obliczona wartosc hasz
 * \return unsigned int- wartosc haszu z podanego stringu
 */
unsigned int TablicaAsocjacyjna::Haszowanie(string nazwa)
{
  unsigned int h,i;
  
  for(i=0,h=0;i<nazwa.length();++i)
    h=h+wzmocnienie*nazwa[i]+nazwa[i];
  return h%rozmiar;
}

/*!
 * Funkcja wyszukujaca dany string w slowniku z wykorzystaniem haszowania
 * \param[] nazwa - string z ktorego zostanie obliczona wartosc hasz
 * \return true-jesli dany string znaleziono, false - nie znaleziono
 */
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
/*!
 * Funkcja tworzaca przykladowy zestaw danych stringow
 * \param[] Strm - referencja do strumieinia wyjsciowego
 * \param[] rozmiarek - typ u_int , ilosc stworzonych stringow
 * \param[] IleLiter - typ int, jak wiele liter ma posiadac dany string
 */
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
