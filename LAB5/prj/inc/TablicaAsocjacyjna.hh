#ifndef TABLICAASOCJACYJNA__HH
#define TABLICAASOCJACYJNA__HH

#include <string>
#include "Struktury.hh"

/*!
 * \file
 * \brief Klasa TablicaAsocjacyjna sluzy do wykonywania zapisywania i 
 * wyszukiwania elementow z wykorzystaniem haszowania
 */
class TablicaAsocjacyjna
{

public:
  /*!
   * brief Informacja o ilosci elementow w slowniku
   */
  unsigned long int rozmiar;
  /*!
   * brief  Zmienna wymagana do haszowania
   */
  unsigned int wzmocnienie;
  /*!
   * brief Zmienna przechowujaca dane wlasciwe(stringi)
   */
  Stack<List<std::string> > slownik;
  /*!
   * brief Konstruktor z parametrem informujacym o rozmiarze slownika
   */
  TablicaAsocjacyjna(unsigned long int roz);
  /*!
   * brief Funkcja haszujaca dany string
   */
  unsigned int Haszowanie(std::string nazwa);
  /*!
   * brief Funkcja Wstawiajaca do slownika dany string, wykorzystujaca haszowanie
   */
  void WstawianieDoTablicy(std::string nazwa);
  /*!
   * brief Funkcja wyszukujaca dany string w slowniku z wykorzystaniem haszowania
   */
  bool Wyszukaj(std::string nazwa);
  /*!
   * brief Funkcja tworzaca przykladowy zestaw danych stringow
   */
  std::ostream& StworzDane(std::ostream &Strm,unsigned int rozmiar,int IleLiter);
  /*!
   * brief Funkcja wstawia dane z pliku do slownika z wykorzystaniem haszowania
   */
  void WstawianieDanychZPliku(std::ifstream& plikwe, int size);

};

#endif
