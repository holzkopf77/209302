#ifndef OPERACJENAPLIKACH_HH
#define OPERACJENAPLIKACH_HH
/*!
 * Funkcja sluzy do wczytania elementow ze strumienia
 * \param[in] &Strm- referencja do strumienia wejsciowego
 * \param IloscDanych - ilosc, jak wiele danych ma byc wczytane
 * \param *dane - wskaznik na strukture do ktorej beda wczytywane dane
 * \return zwraca referencje do strumienia wejsciowego
 */
template<typename T>
std::istream& WczytajDaneZpliku(std::istream &Strm,unsigned long int IloscDanych, T* dane)
{
  for(unsigned long int i=0;i<IloscDanych;++i)
    {
      Strm>>dane[i];
    }
  return Strm;
}
#endif
