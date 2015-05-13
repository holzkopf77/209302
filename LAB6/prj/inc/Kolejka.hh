#ifndef KOLEJKA_HH
#define KOLEJKA_HH
#include "NodeL.hh"
#include "iKolejka.hh"
/**********************************************************************************/

/*!
 * \brief klasa Kolejka sluzy do wykonywania podstawowych operacji na Kolejce:
 * dodaj,odejmij element. Przechowuje informacje o ilosci wszysktich elementow.
 */
template <typename T>
class Kolejka:public iKolejka<T>
{
public:
  /*!
 *brief Konstruktor bezparametryczny
 */
  Kolejka();
  ~Kolejka();
/*!
 *brief Funkcja zwraca rozmiar kolejki
 */
  virtual int size();
/*!
 *brief Funkcja dodaje element na poczatek kolejki
 */
  virtual void  push_front(T value);
  virtual void push(T value);
/*!
 *brief Funkcja zdejmuje element z konca kolejki
 */
  virtual void pop_back();
  virtual void pop();
/*!
 *brief Funkcja wyswietla wszystkie elementy na standardowe wyjscie
 */
  virtual void show();
};

/*!
 * Konstruktor bezparametryczny, ustawia parametry na 0
 */
template <typename T>
Kolejka<T>::Kolejka()
  {
    this->head=nullptr;
    this->_size=0;
  }

/*!
 * Destruktor, usuwa kolejne elementy kolejki zaczynajac od poczatku
 */
template <typename T>
Kolejka<T>::~Kolejka()
  {
    for(NodeL<T> *p; this->head!=nullptr; this->head=p)
      {
	p=this->head->next;
	delete this->head;
      }
  }

/*!
 *\return Funkcja zwraca wartosc rozmiaru kolejki
 */
template <typename T>
int Kolejka<T>::size()
  {
    return this->_size;
  }

/*!
 *Funkcja sluzy do dodania elementu na poczatek kolejki
 *\param[in] value-typ int, wartosc elementu zmiennej dodanej do kolejki
 */
template <typename T>
void  Kolejka<T>::push_front(T value)
  {
    NodeL<T> *p=new NodeL<T>;
    p->val=value;
    p->next=this->head;
    this->head=p;// nowy poczatek kolejki
    ++this->_size;
  }

/*!
 *Funkcja sluzy do dodania elementu na poczatek kolejki
 *\param[in] value-typ int, wartosc elementu zmiennej dodanej do kolejki
 */
template <typename T>
void  Kolejka<T>::push(T value)
  {
    NodeL<T> *p=new NodeL<T>;
    p->val=value;
    p->next=this->head;
    this->head=p;// nowy poczatek kolejki
    ++this->_size;
  }

/*!
 *Funkcja usuwa element z konca kolejki
 *\pre Kolejka nie moze byc pusta
 */
template <typename T>
void Kolejka<T>::pop_back()
{
  NodeL<T> * p = this->head;
  if(p!=nullptr)
  {
    if(p->next!=nullptr) //usuwanie jeśli jest więcej elementów niż tylko head
    {
      while(p->next->next!=nullptr) p = p->next; // szukam przedostatniego z kolejki
      delete p->next; //usuwam ostatniego
      p->next = nullptr; //oznaczam nowy koniec kolejki
    }
    else //był na kolejce tylko head
    {
      delete p;  
      this->head = nullptr; // kolejka staje się kolejka pustą
    }
  }
  else
    {
      throw std::string("Ogarnij sie, kolejka jest pusta");
    }
  --this->_size;
}

/*!
 *Funkcja usuwa element z konca kolejki
 *\pre Kolejka nie moze byc pusta
 */
template <typename T>
void Kolejka<T>::pop()
{
  NodeL<T> * p = this->head;
  if(p!=nullptr)
  {
    if(p->next!=nullptr) //usuwanie jeśli jest więcej elementów niż tylko head
    {
      while(p->next->next!=nullptr) p = p->next; // szukam przedostatniego z kolejki
      delete p->next; //usuwam ostatniego
      p->next = nullptr; //oznaczam nowy koniec kolejki
    }
    else //był na kolejce tylko head
    {
      delete p;  
      this->head = nullptr; // kolejka staje się kolejka pustą
    }
  }
  else
    {
      throw std::string("Ogarnij sie, kolejka jest pusta");
    }
  --this->_size;
}
  
/*!
 *Funkcja wyswietla elementy kolejki
 */
template <typename T>
void Kolejka<T>::show()
{
  NodeL<T>* p=this->head;
  for(int i=0;i<this->_size;++i)
    {
      std::cout<<p->val<<" ";
      p=p->next;
    }
}
#endif
