#ifndef BENCHMARK_HH
#define BENCHMARK_HH
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include "iObserwator.hh"
/*******************************************************************************************************/
/*!
 * \file
 * \brief Klasa Benchmark sluzy do przechowywania wynikow zlozonosci
 * obliczeniowej i danych wejsciowych,generowania liczb rozkladu Gaussowego 
 */
template<typename T>
class Benchmark:public iObserwator<T>
{
public:
    /*!
   * brief wskaznik na tablice przechowujaca wartosci zlozonosci obliczeniowej(ilosc danych,czas)
   */
  unsigned long int **ZlozonoscObliczeniowa;
  /*!
   * brief wskaznik na tablice przechowujaca elementy z rozkladu gaussa
   */
  T *LiczbyGaussowe;
  /*!
   * brief ilosc liczb z rozkladu Gaussa
   */
  int IleRazyWykonanyTest;

  unsigned long int IloscDanych;
  /*!
   * brief ilosc liczb zlozonosci obliczeniowej
   */
  int rozmiar;
  /*!
   * brief Konstruktor bezparametryczny
   */
  Benchmark();
  /*!
   * brief Konstruktor z 2 argumentami int, unsigned long int
   */
  Benchmark(int roz, unsigned long int max, T* Struktura=nullptr);
    /*!
   * brief destruktor klasy Benchmark
   */
  ~Benchmark();
  /*!
   * brief Ustalenie rozmiaru tablicy zlozonosci obliczeniowej
   */
  void UstalRozmiarTablicyZlozonosciObliczeniowej(int roz);
  /*!
   * brief Funkcja generuje  liczby typu double z rozkladu Gaussa
   */
  std::ostream& GenerujLiczbyZmiennoprzecinkowe(long int rozmiar,std::ostream& strum);
/*!
   * brief Funkcja generuje  liczby typu double z rozkladu Gaussa
   */
  std::ostream& GenerujLiczbyCalkowiteLosowe(long  int rozmiar,std::ostream& strum);
  /*!
   *  brief Funkcja zamienia liczby float z rozkladu rownomiernego na Gaussowy
   */
  void TransformacjaBoxa_Mullera(float* a);
  /*!
   * brief Funkcja tworzy wygodne liczby odniesienia dla danej funkcji testowej o zadanym maximum
   */
  void StworzLiczbyOdniesienia(int p[], int ile);
  /*!
   * brief Funkcja mierzy czas trwania funkcji dla okreslonej ilosci danych
   */
  void Testuj(int MaxIloscDanych,
	      void (*wsk_fun)(T*, int));

  std::ostream& ZapiszWynikiZlozonosciObliczeniowej(std::ostream& Strm);
  void odswiez(long int IloscTestowanychDanych, long int CzasStopu);
};

/*!
* Konstruktor parametryczny klasy Benchmark
* \param[in] roz - typ int, rozmiar tablicy ZlozonoscObliczeniowa,
* \param[in] max- unsigned long int, ilosc liczb zmiennoprzecinkowych tablicy LiczbyGaussowe
*/
template<typename T>
Benchmark<T>::Benchmark(int roz,unsigned long int max,T* Struktura)/*: rozmiar(roz),IloscDanych(max)*/
  {
    rozmiar=roz;
    IloscDanych=max;
    ZlozonoscObliczeniowa=new unsigned long int*[rozmiar];
    for(int i=0;i<rozmiar;++i)
      ZlozonoscObliczeniowa[i]=new  unsigned long int[2];
    LiczbyGaussowe=Struktura;
  }

/*!
 * Konstruktor bezparametryczny klasy Benchmark
 * Ustawia wszystkie zmienne i wskazniki na wartosc 0
 */
template<typename T>
Benchmark<T>::Benchmark():rozmiar(0)
  {
    ZlozonoscObliczeniowa=nullptr;
    LiczbyGaussowe=nullptr;
    IloscDanych=0;
    rozmiar=0;
  }
  
template<typename T>
Benchmark<T>::~Benchmark()
  {
    for(int i=0;i<rozmiar;++i)
      delete [] ZlozonoscObliczeniowa[i];
    delete [] ZlozonoscObliczeniowa;
  }
  
/*!
 * Funkcja ustala na nowo rozmiar tablicy ZlozonoscObliczeniowa
 * \param[in] roz - typ int, rozmiar tablicy ZlozonoscObliczeniowa
 * \pre zmienna roz musi byc dodatnia
 */
template<typename T>
void Benchmark<T>::UstalRozmiarTablicyZlozonosciObliczeniowej(int roz)
  {
    for(int i=0;i<rozmiar;++i)
      delete [] ZlozonoscObliczeniowa[i];
    delete [] ZlozonoscObliczeniowa;

    rozmiar=roz;
    ZlozonoscObliczeniowa=new unsigned long int*[rozmiar];
    for(int i=0;i<rozmiar;++i)
      ZlozonoscObliczeniowa[i]=new unsigned long int[2];
  }

/*!
* Funkcja operatorowa pozwala na wypisanie wszystkich liczb tablicy
* LiczbyGaussowe
* \param[in,out] &Strm - referencja do strumienia wyjsciowego
* \param[in,out] &ben refencja do klasy typu Benchmark
* \return Zwraca referencje do strumienia wyjsciowego
* \pre Poprawne wczytanie liczb tablicy LiczbyGaussowe
*/
template<typename T>
std::ostream& operator<<(std::ostream& Strm,const Benchmark<T>& ben)
{
  for (int i = 0; i < (ben.rozmiar); ++i) 
    {
      Strm<<ben.LiczbyGaussowe[i]<<std::endl;
    }
  return Strm;
}

/*!
* Funkcja operatorowa pozwala na wczytanie liczby typu double
* do tablicy LiczbyGaussowe
* \param[in,out] &Strm - referencja do strumienia wejsciowego
* \param[in,out] &ben referencja do klasy typu Benchmark
* \return Zwraca referencje do strumienia wejsciowego
* \pre Liczba tylko typu double
*/
template<typename T>
std::istream& operator >> (std::istream &Strm, Benchmark<T> &ben)
{
  for(unsigned long int i=0;i<ben.IloscDanych;++i)
    {
      Strm>>ben.LiczbyGaussowe[i];
    }
  return Strm;
}

/*!
 * Funkcja generuje liczby typu float o rozkladzie Gaussa i zapisuje do strumienia
 * \param[in] rozmiar - long int, ilosc wygenerowanych elementow
 * \param[in] &strum - referencja do strumienia wyjsciowego
 * \return Zwraca referencje do strumienia wyjsciowego
 * \pre Prawidlowe dzialanie funkcji TransformacjaBoxa_Mullera
 */
template<typename T>
std::ostream& Benchmark<T>::GenerujLiczbyZmiennoprzecinkowe(long  int rozmiar,std::ostream& strum)
{
  const int rozX=2;                                   //2zmienne potrzebne do BoxMullera
  long x[rozX];
  float d[rozX];

  srand(time(NULL));                                 //arg=obecny czas
  for(long int i=0;i<rozmiar;++i)
    {
      for(int j=0;j<rozX;++j)
	{
	  x[j]=((long)rand()<<31)*+rand();
	  if(x[j]<0)x[j]*=-1;
	  d[j]=(float)(x[j]/10e18);
	}
      TransformacjaBoxa_Mullera(d);
      strum<<d[0]<<std::endl;
    }
  return strum;      
}

/*!
 * Funkcja generuje liczby typu int o rozkladzie Gaussa i zapisuje do strumienia
 * \param[in] rozmiar - long int, ilosc wygenerowanych elementow
 * \param[in] &strum - referencja do strumienia wyjsciowego
 * \return Zwraca referencje do strumienia wyjsciowego
 * \pre Prawidlowe dzialanie funkcji TransformacjaBoxa_Mullera
 */
template<typename T>
std::ostream& Benchmark<T>::GenerujLiczbyCalkowiteLosowe(long  int rozmiar,std::ostream& strum)
{
  const int rozX=2;                                   //2zmienne potrzebne do BoxMullera
  long x[rozX];
  float d[rozX];

  srand(time(NULL));                                 //arg=obecny czas
  for(long int i=0;i<rozmiar;++i)
    {
      for(int j=0;j<rozX;++j)
	{
	  x[j]=((long)rand()<<31)*+rand();
	  if(x[j]<0)x[j]*=-1;
	  d[j]=(float)(x[j]/10e18);
	}
      TransformacjaBoxa_Mullera(d);
      strum<<(int)(100*d[0])<<std::endl;
    }
  return strum;      
}

/*!
 * Funkcja zamienia liczby z rozkladu rownomiernego na rozklad Gaussa
 * \param[in] a[] - typ float,wskaznik na tablice 2-elementowa
 * \pre 2 liczby z rozkladu rownomiernego
 */
template<typename T>
void Benchmark<T>::TransformacjaBoxa_Mullera(float *a)
{
  float R2=sqrt(-2*log(a[0]));                   //wzory na transformate z wikipedii
  float theta=2*M_PI*a[1];
  a[0]=R2*cos(theta);
  a[1]=R2*sin(theta);
}

/*!
 * Funkcja sluzy do badania zlozonosci obliczeniowej danej funkcji
 * \param[in] MaxIloscDanych - int, maksymalna ilosc danych do testu
 * \param[in] wsk_fun= wskaznik na funkcje testowana o arg:double*,int
 * \pre Funkcja w argumencie musi być typu(TypSzablonuBenchmark,maxLiczbaElementow)
 * \pre Ilosc cykli ustawia sie w konstruktorze Benchmarku,maxElem=75 000 000
 */
template<typename T>
void Benchmark<T>::Testuj(int MaxIloscDanych,
		       void (*wsk_fun)(T*,int))
{
  int IloscPowtorzen=rozmiar;
  const int IloscLiczbOdniesienia=28; //ostatnia liczba to 75 000 000,
  int LiczbyOdniesienia[IloscLiczbOdniesienia];
  int IndeksMaxLiczby=IloscLiczbOdniesienia-1;
  int Bonus=0;

  StworzLiczbyOdniesienia(LiczbyOdniesienia,IloscLiczbOdniesienia);
  for(;LiczbyOdniesienia[IndeksMaxLiczby]>MaxIloscDanych;--IndeksMaxLiczby);
  int KrokOdniesienia= (IndeksMaxLiczby+1)/IloscPowtorzen;
  double BonusDoKroku=(double)((IndeksMaxLiczby+1)%IloscPowtorzen)/(double)IloscPowtorzen;

  if(BonusDoKroku<0.25)Bonus=0;
  else if(BonusDoKroku<0.5)Bonus=4;
  else Bonus=2;

  for(int i=0,j=0;i<(IndeksMaxLiczby+1)&& j+1<IloscPowtorzen;i+=KrokOdniesienia,++j)
    {
      std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
      wsk_fun(LiczbyGaussowe,LiczbyOdniesienia[i]);
      auto elapsed = std::chrono::high_resolution_clock::now() - start;
      auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
      ZlozonoscObliczeniowa[j][0]=LiczbyOdniesienia[i];
      ZlozonoscObliczeniowa[j][1]=microseconds;
      if(((Bonus)&&(!((i+1)%Bonus))))++i;
      std::cout<<LiczbyOdniesienia[i]<<std::endl;
    }

      std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
      wsk_fun(LiczbyGaussowe,MaxIloscDanych);
      auto elapsed = std::chrono::high_resolution_clock::now() - start;
      auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
      ZlozonoscObliczeniowa[IloscPowtorzen-1][0]=MaxIloscDanych;
      ZlozonoscObliczeniowa[IloscPowtorzen-1][1]=microseconds;
  
}

/*!
 * Funkcja tworzy liczby odniesienia, by lepiej dobrac ilosci danych do testu
 * \param[in] *p - int*, w tablicy ustalane sa argumenty liczb odniesienia
 * \param[in] ile-int, jak duzo ma zostac stworzonych liczb odniesienia
 * \pre Ilosc liczb odniesienia musi byc podzielna przez 4
 */
template<typename T>
void Benchmark<T>::StworzLiczbyOdniesienia(int *p, int ile)
{
  const  int a=10,b=25,c=50,d=75;
  for(int i=0,mnoznik=1;i<ile;i+=4,mnoznik*=10)
    {
      p[i]=a*mnoznik;
      p[i+1]=b*mnoznik;
      p[i+2]=c*mnoznik;
      p[i+3]=d*mnoznik;
    }
}

/*!
 * Funkcja sluzy do zapisania wynikow z tablicy ZlozonoscObliczeniowa
 * \param[in] &Strum - referencja do strumienia wyjsciowego
 * \param[in] roz - ilosc elementow w tablicy ZlozonoscObliczniowa przez 2
 * \return Zwraca referencje do strumienia wyjsciowego
 * \pre Poprawnie wczytane wartosci tablicy ZlozonoscObliczeniowa
 */
template<typename T>
std::ostream& Benchmark<T>::ZapiszWynikiZlozonosciObliczeniowej(std::ostream& Strm)
{
  for(int i=0;i<rozmiar;++i)
    Strm<<ZlozonoscObliczeniowa[i][0]<<" "<<ZlozonoscObliczeniowa[i][1]<<std::endl;
  return Strm;
}

template<typename T>
void Benchmark<T>::odswiez(long int IloscTestowanychDanych, long int CzasStopu)
{
  ZlozonoscObliczniowa[IleRazyWykonanyTest][0]=IloscTestowanychDanych;
  ZlozonoscObliczeniowa[IleRazyWykonanyTest][1]=CzasStopu;
 ++IleRazyWykonanyTest;
}

#endif







