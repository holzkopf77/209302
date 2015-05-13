#ifndef ILISTA__HH
#define ILISTA__HH
#include "iKontenery.hh"

template <typename T>
class iList:public iKontenery<T>
{
public:
  /*!
   *brief wskaznik do ktorego doczepione sa kolejne elementy
   */
  NodeL<T> *head;
  /*!
   *brief wskaznik pokazujacy na koniec listy
   */
  NodeL<T> *tail;
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
/*!
 *brief Funkcja zdejmuje element z poczatku listy
 */
  virtual   void pop_front()=0;
/*!
 *brief Funkcja dodaje element na koniec listy
 */
  virtual   void push_back(T value)=0;
/*!
 *brief Funkcja pokazujaca na strumieniu std::cout zawartosc listy
 */ 
  virtual  void push(T value,int nr)=0;
};
#endif
