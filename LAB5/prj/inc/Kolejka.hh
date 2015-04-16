#ifndef KOLEJKA_HH
#define KOLEJKA_HH
/**********************************************************************************/
/*!
 * \file
 * \brief Struktura przechowujaca wartosc wezla i wskaznik na
 * nastepny element typu Node
 */
template <typename T>
struct  Node
{
  T  val;
  Node<T> * next;
};

/*!
 * \brief klasa Kolejka sluzy do wykonywania podstawowych operacji na Kolejce:
 * dodaj,odejmij element. Przechowuje informacje o ilosci wszysktich elementow.
 */
template <typename T>
class Kolejka
{
/*!
 *brief wskaznik do ktorego doczepione sa kolejne elementy
 */
  Node<T> *head;
/*!
 *brief Informacja o rozmiarze kolejki
 */
  int _size;
public:
  /*!
 *brief Konstruktor bezparametryczny
 */
  Kolejka();
  ~Kolejka();
/*!
 *brief Funkcja zwraca rozmiar kolejki
 */
  int size();
/*!
 *brief Funkcja dodaje element na poczatek kolejki
 */
  void  push_front(T value);
/*!
 *brief Funkcja zdejmuje element z konca kolejki
 */
  void pop_back();
/*!
 *brief Funkcja wyswietla wszystkie elementy na standardowe wyjscie
 */
  void show();
};

/*!
 * Konstruktor bezparametryczny, ustawia parametry na 0
 */
template <typename T>
Kolejka<T>::Kolejka()
  {
    head=nullptr;
    _size=0;
  }

/*!
 * Destruktor, usuwa kolejne elementy kolejki zaczynajac od poczatku
 */
template <typename T>
Kolejka<T>::~Kolejka()
  {
    for(Node<T> *p; head!=nullptr; head=p)
      {
	p=head->next;
	delete head;
      }
  }

/*!
 *\return Funkcja zwraca wartosc rozmiaru kolejki
 */
template <typename T>
int Kolejka<T>::size()
  {
    return _size;
  }

/*!
 *Funkcja sluzy do dodania elementu na poczatek kolejki
 *\param[in] value-typ int, wartosc elementu zmiennej dodanej do kolejki
 */
template <typename T>
void  Kolejka<T>::push_front(T value)
  {
    Node<T> *p=new Node<T>;
    p->val=value;
    p->next=head;
    head=p;// nowy poczatek kolejki
    ++_size;
  }

/*!
 *Funkcja usuwa element z konca kolejki
 *\pre Kolejka nie moze byc pusta
 */
template <typename T>
void Kolejka<T>::pop_back()
{
  Node<T> * p = head;
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
      head = nullptr; // kolejka staje się kolejka pustą
    }
  }
  else
    {
      throw std::string("Ogarnij sie, kolejka jest pusta");
    }
  --_size;
}
  
/*!
 *Funkcja wyswietla elementy kolejki
 */
template <typename T>
void Kolejka<T>::show()
{
  Node<T>* p=head;
  for(int i=0;i<_size;++i)
    {
      std::cout<<p->val<<" ";
      p=p->next;
    }
}
#endif
