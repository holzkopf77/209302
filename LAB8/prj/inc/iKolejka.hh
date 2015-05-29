#ifndef IKOLEJKA__HH
#define IKOLEJKA__HH
#include "iKontenery.hh"

template <typename T>
class iKolejka:public iKontenery<T>
{
public:
  /*!
   *brief wskaznik do ktorego doczepione sa kolejne elementy
   */
  NodeL<T> *head;
  /*!
   *brief Informacja o rozmiarze kolejki
   */
  int _size;

  virtual int size()=0;
/*!
 *brief Funkcja dodaje element na poczatek listy
 */
  virtual void  push_front(T value)=0;
/*!
 *brief Funkcja zdejmuje element z konca listy
 */
  virtual   void pop_back()=0;
};
#endif
