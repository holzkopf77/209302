#ifndef ISTACK__HH
#define ISTACK__HH
#include "iKontenery.hh"

template <typename T>
class iStack:public iKontenery<T>
{
public:
  /*
   *brief Funkcja zwraca rozmiar stosu
   */
  virtual  int size()=0;
  /*
   *brief Funkcja zwraca ostatni element stosu
   */
  virtual T peek()=0;
  /*
   *brief wskaznik na ostatatni +1 element stosu
   */
  T *top;
  /*
   *brief biezaca pojemnosc stosu, wieksza,rowna od ilosci elementow
   */
  int capacity;
  /*
   *brief wskaznik na pierwszy element stosu
   */
  T *storage;
};
#endif
