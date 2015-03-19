#ifndef BENCHMARK_HH
#define BENCHMARK_HH

/*******************************************************************************************************/
/*!
 * \file
 * \brief Klasa Benchmark sluzy do przechowywania wynikow zlozonosci
 * obliczeniowej i danych wejsciowych,generowania liczb rozkladu Gaussowego 
 */
class Benchmark
{
public:
    /*!
   * brief wskaznik na tablice przechowujaca wartosci zlozonosci obliczeniowej(ilosc danych,czas)
   */
  long int **ZlozonoscObliczeniowa;
  /*!
   * brief wskaznik na tablice przechowujaca elementy z rozkladu gaussa
   */
  double *LiczbyGaussowe;
  /*!
   * brief ilosc liczb z rozkladu Gaussa
   */
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
  Benchmark(int roz, unsigned long int max);
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
   *  brief Funkcja zamienia liczby float z rozkladu rownomiernego na Gaussowy
   */
  void TransformacjaBoxa_Mullera(float a[]);
  /*!
   * brief Funkcja tworzy wygodne liczby odniesienia dla danej funkcji testowej o zadanym maximum
   */
  void StworzLiczbyOdniesienia(int p[], int ile);
  /*!
   * brief Funkcja mierzy czas trwania funkcji dla okreslonej ilosci danych
   */
  void Testuj(int IloscPowtorzen, int MaxIloscDanych,
	      void (*wsk_fun)(double*, int));
  std::ostream& ZapiszWynikiZlozonosciObliczeniowej(std::ostream& Strm,int roz);
};

/*!
 * brief  Wypisanie liczb z rozkladu Gaussa
 */
std::ostream& operator<<(std::ostream& Strm,const Benchmark& ben);
/*!
 * brief  Wczytanie liczb z rozkladu Gaussa
 */
std::istream& operator>>(std::istream &Strm,Benchmark &ben);

#endif




