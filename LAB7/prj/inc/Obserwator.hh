#ifndef OBSERWATOR_HH
#define OBSERWATOR_HH
#include <fstream>
#include "iObserwator.hh"
template<typename T>
class Obserwator:public iObserwator<T>
{
public:
  int rozmiar;
  int IleRazyWykonanyTest;
  unsigned long int **ZlozonoscObliczeniowa;
  Obserwator();
  Obserwator(int roz, unsigned long int max, T* Struktura=nullptr);
  ~Obserwator();
  void odswiez(long int IloscTestowanychDanych, long int CzasStopu);
  void clear();
  void zapisz(std::ostream &Strm);
};

template<typename T>
void Obserwator<T>::odswiez(long int IloscTestowanychDanych, long int CzasStopu)
{
  ZlozonoscObliczeniowa[IleRazyWykonanyTest][0]=IloscTestowanychDanych;
  ZlozonoscObliczeniowa[IleRazyWykonanyTest][1]=CzasStopu;
 ++IleRazyWykonanyTest;
}

template<typename T>
Obserwator<T>::Obserwator()
  {
    rozmiar=10;	
    ZlozonoscObliczeniowa=new unsigned long int*[rozmiar];
    for(int i=0;i<rozmiar;++i)
      ZlozonoscObliczeniowa[i]=new  unsigned long int[2];
    IleRazyWykonanyTest=0;
  }
  
template<typename T>
Obserwator<T>::~Obserwator()
  {
    for(int i=0;i<rozmiar;++i)
      delete [] ZlozonoscObliczeniowa[i];
    delete [] ZlozonoscObliczeniowa;
  }

template<typename T>
void Obserwator<T>::clear()
  {
    for(int i=0;i<rozmiar;++i)
      delete [] ZlozonoscObliczeniowa[i];
    delete [] ZlozonoscObliczeniowa;
    ZlozonoscObliczeniowa=new unsigned long int*[rozmiar];
    for(int i=0;i<rozmiar;++i)
      ZlozonoscObliczeniowa[i]=new  unsigned long int[2];
    IleRazyWykonanyTest=0;
  }

template<typename T>
void Obserwator<T>::zapisz(std::ostream &Strm)
{
  for(int i=0;i<IleRazyWykonanyTest;++i){
    Strm<<ZlozonoscObliczeniowa[i][0];//ilosc danych
    Strm<<" ";
    Strm<<ZlozonoscObliczeniowa[i][1];//czas stopu
    Strm<<std::endl;
  }
    
}
#endif
