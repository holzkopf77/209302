#include <string>
#include <iostream>
#include "Struktury.hh"
#include "ZapiszStosKolejkaLista.hh"

//Funkcje powstaly po to by sprawdzic zlozonosc zapisywania danych do struktur

/*!
 * Funkcja sluzy do zapisywania danych na stosie utworzonym w tej funkcji
 * \param[] Gausowe - typ double *, wskaznik na tablice typu double
 * \param[] size - rozmiar, jak wiele liczb ma byc zapisane
 */
void ZapiszKolejnoLiczbyStosu(double* Gausowe,int size)
{
  Stack<double> stos(1);
  for(long int i=0;i<size;++i)
    stos.push(Gausowe[i]);
}

/*!
 * Funkcja sluzy do zapisywania danych na liscie utworzonej w tej funkcji
 * \param[] Gausowe - typ double *, wskaznik na tablice typu double
 * \param[] size - rozmiar, jak wiele liczb ma byc zapisane
 */
void ZapiszKolejnoLiczbyListy(double* Gausowe,int size)
{
  List<double> lista;
  for(long int i=0;i<size;++i)
    lista.push_back(Gausowe[i]);
}

/*!
 * Funkcja sluzy do zapisywania danych na Kolejce utworzonej w tej funkcji
  *\param[] Gausowe - typ double *, wskaznik na tablice typu double
 * \param[] size - rozmiar, jak wiele liczb ma byc zapisane
 */
void ZapiszKolejnoLiczbyKolejki(double* Gausowe,int size)
{
  Kolejka<double> kolejeczka;
  for(long int i=0;i<size;++i)
    kolejeczka.push_front(Gausowe[i]);
}

/*!
 * Funkcja sluzy do Wczytania Listy o elementach typu int
 * \param[] Strm - referencja do strumienia wejsciowego
 * \param[] IloscDanych - typ int, oznacza jak wiele danych ma byc wczytane
 * \param[] dane - typ List<int>*, lista gdzie beda wczytane dane
 */
void WczytajListe(std::istream &Strm,unsigned long int IloscDanych, List<int> * dane)
{
  int a;
  for(int i=0;i<IloscDanych;++i){
    Strm>>a;
    dane->push_front(a);
  }
}
