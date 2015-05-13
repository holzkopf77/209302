#ifndef STACK__HH
#define STACK__HH
#include "iStack.hh"
#include <string>
/**********************************************************************************************/
/*!
 * \file
 * \brief Klasa Stack sluzy do przechowywania, dodawania,zdejmowania
 * kolejnych elementow stosu
 */
template <typename T>
class Stack: public iStack<T>
{
public:
  /*
   *brief Konstruktor parametryczny klasy Stack
   */
  Stack(int capacity=10);
  /*
   *brief Funkcja dodaje element na koniec stosu
   */
  void  push(T value);
  /*
   *brief Funkcja zwraca ostatni element stosu
   */
  T peek();
  /*
   *brief Funkcja zwraca rozmiar stosu
   */
  int  size();
  /*
   *brief Destruktor klasy Stack
   */
  ~Stack();
  /*
   *brief Funkcja zdejmuje ostatni element stosu
   */
  void pop();
  /*!
   * brief Przeciazony operator indeksowania, umozliwia traktowanie stosu jak tablicy
   */
    T& operator[](int a)
  {
    return *(this->storage+a);
  }

};

/*!
 * Konstruktor parametryczny klasy Stack
 * \param[in] capacity - typ int, rozmiar stosu
 */
template<typename T>
Stack<T>::Stack(int capacity)
{
  /*  iStack<T>::*/this->top=nullptr;
  this->capacity=capacity;
  if(capacity<=0)
    throw std::string("Pojemnosc stosu musi byc dodatnia");
  this->storage=new T[capacity]; //throw catch capacity za duze
  this->capacity=capacity;
  this->top=this->storage;
}

/*!
 * Funkcja dodaje element na koniec tablicy stosu
 * \param[in] value - typ int, wartosc dodana do stosu
 * \post wykorzystana metoda podwajania do powiekszania stosu
 */
template<typename T>
void  Stack<T>::push(T value)
{
  if((this->top-this->storage)==this->capacity)
    {
      //throw string("Pojemnosc stostu jest pelna,operacja nieudana");
      T *nowaTablica=new T [this->capacity*2];
      for(int i=0;i<this->capacity;++i)
	  nowaTablica[i]=this->storage[i];
      delete []this->storage;
      this->storage=nowaTablica;
      this->top=this->storage+this->capacity;
      this->capacity*=2;
    }
  *this->top++=value;
}

/*!
 * Funkcja pokazuje element znajdujacy sie na szczycie stosu
 * \pre Stos nie moze byc pusty
 */
template<typename T>
T Stack<T>::peek()
{
  if(this->top==this->storage)
    throw std::string("Stos jest pusty");
  return *(this->top-1);
}

/*!
 * Funkcja pokazuje ilosc elementow stosu
 * \return zwraca ilosc elementow stosu
 */
template<typename T>
int  Stack<T>::size()
{
  return this->top-this->storage;
}

/*!
 * Destruktor klasy Stack
 */
template<typename T>
Stack<T>::~Stack()
{
  delete [] this->storage;
  this->top=nullptr;
}

/*!
 * Funkcja pop zdejmuje ostatni element ze stosu
 * \pre Stos nie moze byc pusty
 */
template<typename T>
void Stack<T>::pop()
{
  if(this->top==this->storage)
    throw std::string("Stos jest pusty, nie mozna zdjac zadnego elementu");
  --this->top;
}

/*!
 * Funkcja operatorowa sluzy do wyswietlania stosu,zbedna
 * \param[in] &out - referencja do strumienia wyjsciowego
 * \param[in] &stack- referencja do stosu
 * \return zwraca referencje do strumienia wyjsciowego
 */

template<typename T>
std::ostream& operator<<(std::ostream &out,const Stack<T> &stack)
{
  T *wsk=stack.storage;
  while(wsk!=stack.top){out<<*wsk++<<" ";}
  return out;
}

#endif
