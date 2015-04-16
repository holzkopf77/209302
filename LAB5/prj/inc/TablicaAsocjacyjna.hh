#ifndef TABLICAASOCJACYJNA__HH
#define TABLICAASOCJACYJNA__HH
#include <string>
#include "Struktury.hh"
class TablicaAsocjacyjna
{
public:
  unsigned long int rozmiar;
  unsigned int wzmocnienie;
  Stack<List<std::string> > slownik;
  TablicaAsocjacyjna(unsigned long int roz);
  unsigned int Haszowanie(std::string nazwa);
  void WstawianieDoTablicy(std::string nazwa);
  bool Wyszukaj(std::string nazwa);
  std::ostream& StworzDane(std::ostream &Strm,unsigned int rozmiar,int IleLiter);
  void WstawianieDanychZPliku(std::ifstream& plikwe, int size);
  /*string& operator[](string Nazwa)
  {
    if(a+1>_size)throw std::string("Indeks większy niż ilosc elementów na liscie");
    NodeL<T> *p=head;
    for(int i=0;i<a;++i)p=p->next;
    return (p->val);
    }*/

};

#endif
