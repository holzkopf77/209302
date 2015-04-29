#ifndef LIST__HH
#define LIST__HH
#include <string>
#include <iostream>
/**********************************************************************************/
/*!
 * \file
 * \brief Struktura przechowujaca wartosc wezla i wskaznik na
 * nastepny element typu Node
 */
template<typename T>
struct  NodeL
{
  T  val;
  NodeL<T> * next;
  NodeL<T> *prev;
};


/*!
 * \brief klasa List sluzy do wykonywania podstawowych operacji na Liscie:
 * dodaj,odejmij element. Przechowuje informacje o ilosci wszysktich elementow.
 */
template<typename T>
class List
{
public:
/*!
 *brief wskaznik do ktorego doczepione sa kolejne elementy listy
 */
  NodeL<T> *head;
  /*!
   *brief wskaznik pokazujacy na koniec listy
   */
  NodeL<T> *tail;
/*!
 *brief Informacja o rozmiarze listy
 */
  int _size;
public:
/*!
 *brief Konstruktor bezparametryczny
 */
  List();
/*!
 *brief Destruktor
 */
  ~List();
/*!
 *brief Funkcja zwraca rozmiar listy
 */
  int size();
/*!
 *brief Funkcja dodaje element na poczatek listy
 */
  void  push_front(T value);
/*!
 *brief Funkcja zdejmuje element z poczatku listy
 */
  void pop_front();
/*!
 *brief Funkcja dodaje element na koniec listy
 */
  void push_back(T value);
/*!
 *brief Funkcja zdejmuje element z konca listy
 */
  void pop_back();
/*!
 *brief Funkcja wyswietla wszystkie elementy na standardowe wyjscie
 */
/*!
 *brief Funkcja pokazujaca na strumieniu std::cout zawartosc listy
 */
  void show();
  /*!
   *brief Funkcja pokazujaca na strumieniu std::cout zawartosc listy od konca
   */
  void showOdKonca();
  /*!
   *brief Funkcja dodaje element przed elementem o indeksie nr
   */
  void push(T value,int nr=0);
  /*!
   * Przeciazony operator indeksowania zwraca referencje do elementu o indeksie a
   */
  T& operator[](int a)
  {
    NodeL<T> *p=head;
    for(int i=0;i<a;++i)p=p->next;
    return (p->val);
  }
  
};


/*!
 * Konstruktor bezparametryczny, ustawia parametry na 0
 */
template <typename T>
List<T>::List()
  {
    head=nullptr;
    tail=nullptr;
    _size=0;
  }

/*!
 * Destruktor, usuwa kolejne elementy listy zaczynajac od poczatku
 */
template <typename T>
List<T>::~List()
  {
    for(NodeL<T> *p; head!=nullptr; head=p)
      {
	p=head->next;
	delete head;
      }
  }

/*!
 *\return Funkcja zwraca wartosc rozmiaru listy
 */
template <typename T>
int List<T>::size()
  {
    return _size;
  }
  
/*!
 *Funkcja sluzy do dodania elementu na poczatek listy
 *\param[in] value-typ int, wartosc elementu zmiennej dodanej do listy
 */
template <typename T>
void  List<T>::push_front(T value)
  {
    NodeL<T> *p=new NodeL<T>;
    p->val=value;
    p->next=head;
    p->prev=nullptr;
    if(size())head->prev=p;
    head=p;// nowy poczatek listy
    if(!(size()))tail=head;
    ++_size;
  }

/*!
 *Funkcja usuwa element z poczatku listy
 *\pre Lista nie moze byc pusta
 */
template <typename T>
void List<T>::pop_front()
  {
    NodeL<T> *p=head;
    if(p!=nullptr)
      {
	head=p->next;
	head->prev=nullptr;
	delete p;
	--_size;
      }
    else
      throw std::string("Lista pusta, ogarnij sie");
  }

/*!
 *Funkcja dodaje element na koniec listy
 *\param[in] value - typ int, wartosc elementu dodanego na koniec listy
 */
template <typename T>
void List<T>::push_back(T value)
{
  NodeL<T> * p, * n;
  n = new NodeL<T>;  // tworze nowy element
  n->next = nullptr;   // będzie wyznaczał koniec listy
  n->val = value;       //I przechowywał podaną wartość
  p = head;
  if(p!=nullptr) //jeśli lista nie jest pusta
  {
     while(p->next!=nullptr) p = p->next; //szukam końca listy
     p->prev=p;
     p->next = n; //wstawiam na końcowy zamiast nullptr
     tail=n;
  }
  else {head = n;tail=head;}
  ++_size;
}

/*!
 * Funkcja dodaje element przed elementem o indeksie nr
 * \param[in] value-wybrany typ, wartosc elementu dodanego do listy
 * \param[in] nr- indeks elementu przed ktorym ma byc dodany element
 * \pre indeksowanie od 0
 */  
template<typename T>
void List<T>::push(T value,int nr)
{
  NodeL<T> *p,*n;
  int licznik=0;
  n= new NodeL<T>;
  n->val=value;
  p=head;
  if(p!=nullptr && nr)
    {
      if(size()<nr)throw std::string("Operacja niemozliwa,lista jest za krotka");
      for(;licznik<nr-1 || p==nullptr;++licznik)
	p=p->next;
      n->next=p->next;
      p->next=n;
    }
  else if(p!=nullptr)
    {
    n->val=value;
    n->next=head;
    head=n;// nowy poczatek listy
    }
  else{
       n->next=nullptr;
       head=n;
       }
  ++_size;
}

/*!
 *Funkcja usuwa element z konca listy
 *\pre Lista nie moze byc pusta
 */
template <typename T>
void List<T>::pop_back()
{
  NodeL<T> * p = head;
  if(p!=nullptr)
  {
    if(p->next!=nullptr) //usuwanie jeśli jest więcej elementów niż tylko startowy
    {
      while(p->next->next!=nullptr) p = p->next; // szukam przedostatniego z listy
      tail=tail->prev;
      delete p->next; //usuwam ostatniego
      p->next = nullptr; //oznaczam nowy koniec listy
    }
    else
    {
      delete p;  
      head = nullptr; // lista staje się listą pustą
      tail=nullptr;
    }
  }
  else
    {
      throw std::string("Ogarnij sie, lista jest pusta");
    }
  --_size;
}
  
/*!
 *Funkcja wyswietla elementy listy
 */
template <typename T>
void List<T>::show()
{
  NodeL<T>* p=head;
  for(int i=0;i<_size;++i)
    {
      std::cout<<p->val<<" ";
      p=p->next;
    }
}

/*!
 *Funkcja wyswietla elementy listy od konca
 */
template <typename T>
void List<T>::showOdKonca()
{
  std::cout<<"and"<<std::endl;
  NodeL<T>* p=tail;
  for(int i=0;i<_size;++i)
    {
      std::cout<<p->val<<" ";
      p=p->prev;
    }
}

#endif
