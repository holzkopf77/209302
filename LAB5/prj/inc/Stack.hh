#ifndef STACK__HH
#define STACK__HH
#include <string>
/**********************************************************************************************/
/*!
 * \file
 * \brief Klasa Stack sluzy do przechowywania, dodawania,zdejmowania
 * kolejnych elementow stosu
 */
template <typename T>
class Stack
{
public:
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
  
    T& operator[](int a)
  {
    return *(top+a);
  }

};
/*
 *brief Wypisanie stosu
 /
template<typename T>
std::ostream& operator<<(std::ostream &out,const Stack<T> &stack);
*/

/*!
 * Konstruktor parametryczny klasy Stack
 * \param[in] capacity - typ int, rozmiar stosu
 */
template<typename T>
Stack<T>::Stack(int capacity)
{
  top=nullptr;
  this->capacity=capacity;
  if(capacity<=0)
    throw std::string("Pojemnosc stosu musi byc dodatnia");
  storage=new T[capacity]; //throw catch capacity za duze
  this->capacity=capacity;
  top=storage;
}

/*!
 * Funkcja dodaje element na koniec tablicy stosu
 * \param[in] value - typ int, wartosc dodana do stosu
 * \post wykorzystana metoda podwajania do powiekszania stosu
 */
template<typename T>
void  Stack<T>::push(T value)
{
  if((top-storage)==capacity)
    {
      //throw string("Pojemnosc stostu jest pelna,operacja nieudana");
      T *nowaTablica=new T [capacity*2];
      for(int i=0;i<capacity;++i)
	  nowaTablica[i]=storage[i];
      delete []storage;
      storage=nowaTablica;
      top=storage+capacity;
      capacity*=2;
    }
  *top++=value;
}

/*!
 * Funkcja pokazuje element znajdujacy sie na szczycie stosu
 * \pre Stos nie moze byc pusty
 */
template<typename T>
T Stack<T>::peek()
{
  if(top==storage)
    throw std::string("Stos jest pusty");
  return *(top-1);
}

/*!
 * \return zwraca ilosc elementow stosu
 */
template<typename T>
int  Stack<T>::size()
{
  return top-storage;
}

/*!
 * Destruktor klasy Stack
 */
template<typename T>
Stack<T>::~Stack()
{
  delete [] storage;
  top=nullptr;
}

/*!
 * Funkcja pop zdejmuje ostatni element ze stosu
 * \pre Stos nie moze byc pusty
 */
template<typename T>
void Stack<T>::pop()
{
  if(top==storage)
    throw std::string("Stos jest pusty, nie mozna zdjac zadnego elementu");
  --top;
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
