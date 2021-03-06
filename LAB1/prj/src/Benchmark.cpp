#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include "Benchmark.hh"
using namespace std;
/*!
 *\file
 *brief Definicja metod klasy Benchmark
 *
 *Zawiera definicje metod klasy Benchmark
 */

/*!
* Konstruktor parametryczny klasy Benchmark
* \param[in] roz - typ int, rozmiar tablicy ZlozonoscObliczeniowa,
* \param[in] max- unsigned long int, ilosc liczb zmiennoprzecinkowych tablicy LiczbyGaussowe
*/
Benchmark::Benchmark(int roz,unsigned long int max)/*: rozmiar(roz),IloscDanych(max)*/
  {
    rozmiar=roz;
    IloscDanych=max;
    ZlozonoscObliczeniowa=new long int*[rozmiar];
    for(int i=0;i<rozmiar;++i)
      ZlozonoscObliczeniowa[i]=new  long int[2];
    LiczbyGaussowe=new double[IloscDanych];
  }

/*!
 * Konstruktor bezparametryczny klasy Benchmark
 * Ustawia wszystkie zmienne i wskazniki na wartosc 0
 */
  Benchmark::Benchmark():rozmiar(0)
  {
    ZlozonoscObliczeniowa=0;
    LiczbyGaussowe=0;
    IloscDanych=0;
    rozmiar=0;
  }
  
  Benchmark::~Benchmark()
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
  void Benchmark::UstalRozmiarTablicyZlozonosciObliczeniowej(int roz)
  {
    for(int i=0;i<rozmiar;++i)
      delete [] ZlozonoscObliczeniowa[i];
    delete [] ZlozonoscObliczeniowa;

    rozmiar=roz;
    ZlozonoscObliczeniowa=new  long int*[rozmiar];
    for(int i=0;i<rozmiar;++i)
      ZlozonoscObliczeniowa[i]=new  long int[2];
  }

/*!
* Funkcja operatorowa pozwala na wypisanie wszystkich liczb tablicy
* LiczbyGaussowe
* \param[in,out] &Strm - referencja do strumienia wyjsciowego
* \param[in,out] &ben refencja do klasy typu Benchmark
* \return Zwraca referencje do strumienia wyjsciowego
* \pre Poprawne wczytanie liczb tablicy LiczbyGaussowe
*/
ostream& operator<<(ostream& Strm,const Benchmark& ben)
{
  for (int i = 0; i < (ben.rozmiar); ++i) 
    {
      Strm<<ben.LiczbyGaussowe[i]<<endl;
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
istream& operator >> (istream &Strm, Benchmark &ben)
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
ostream& Benchmark::GenerujLiczbyZmiennoprzecinkowe(long  int rozmiar,ostream& strum)
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
      strum<<d[0]<<endl;
    }
  return strum;      
}

/*!
 * Funkcja zamienia liczby z rozkladu rownomiernego na rozklad Gaussa
 * \param[in] a[] - typ float,wskaznik na tablice 2-elementowa
 * \pre 2 liczby z rozkladu rownomiernego
 */
void Benchmark::TransformacjaBoxa_Mullera(float a[])
{
  float R2=sqrt(-2*log(a[0]));                   //wzory na transformate z wikipedii
  float theta=2*M_PI*a[1];
  a[0]=R2*cos(theta);
  a[1]=R2*sin(theta);
}

/*!
 * Funkcja sluzy do badania zlozonosci obliczeniowej danej funkcji
 * \param[in] IloscPowtorzen -  int, ile razy bedzie wykonany test
 * \param[in] MaxIloscDanych - int, maksymalna ilosc danych do testu
 * \param[in] wsk_fun= wskaznik na funkcje testowana o arg:double*,int
 * \pre Poprawne dzialanie funkcji StworzLiczbyOdniesienia
 */
void Benchmark::Testuj(int IloscPowtorzen, int MaxIloscDanych,
		       void (*wsk_fun)(double*,int))
{
  const int IloscLiczbOdniesienia=24; //ostatnia liczba to 7 500 000,
  int LiczbyOdniesienia[IloscLiczbOdniesienia];
  
  StworzLiczbyOdniesienia(LiczbyOdniesienia,IloscLiczbOdniesienia);
  
  int IndeksMaxLiczby=IloscLiczbOdniesienia-1;
  for(;LiczbyOdniesienia[IndeksMaxLiczby]>MaxIloscDanych;--IndeksMaxLiczby);
  int KrokOdniesienia= (IndeksMaxLiczby+1)/IloscPowtorzen;
  double BonusDoKroku=(double)((IndeksMaxLiczby+1)%IloscPowtorzen)/(double)IloscPowtorzen;
  int Bonus;
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
void Benchmark::StworzLiczbyOdniesienia(int *p, int ile)
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
ostream& Benchmark::ZapiszWynikiZlozonosciObliczeniowej(ostream& Strm,int roz)
{
  for(int i=0;i<roz;++i)
    Strm<<ZlozonoscObliczeniowa[i][0]<<" "<<ZlozonoscObliczeniowa[i][1]<<endl;
  return Strm;
}
