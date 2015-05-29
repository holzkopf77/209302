#ifndef GRAF__HH
#define GRAF__HH

#include <vector>
#include <list>
#include <queue>

template <typename T>
class Graf
{
public:
  std::vector<std::list<T>> ListaSasiedztwa;
  std::vector<T> SzukanaDroga;
  std::vector<bool> Odwiedzony;
  int VertexNumber;
  long int RozmiarTestowanychDanych;
  long int StopCzas;
  bool znaleziony;

  Graf(int wierzcholki);
  void add(int start,int koniec);
  void ZnajdzDrogeDFS(int start,int koniec);
  void ZnajdzDrogeBFS(int start,int koniec);
  void printDroga();
  //  bool find(T value);
  void print();
};

template <typename T>
Graf<T>::Graf(int wierzcholki)
  {
    RozmiarTestowanychDanych=0;
    StopCzas=0;
    VertexNumber=wierzcholki;
    znaleziony=false;
    for(int i=0;i<VertexNumber;++i)
      {
	std::list<T> lista;
	ListaSasiedztwa.push_back(lista);
	Odwiedzony.push_back(false);
      }
  }

template <typename T>
void Graf<T>::add(int start, int koniec)
  {
    ListaSasiedztwa[start].push_front(koniec);
  }

template <typename T>
void Graf<T>::ZnajdzDrogeDFS(int start,int koniec)
{
  Odwiedzony[start]=true;
  SzukanaDroga.push_back(start);
  for (std::list<int>::iterator it=ListaSasiedztwa[start].begin(); it!=ListaSasiedztwa[start].end(); ++it)
    {
      if(start==koniec||znaleziony){znaleziony=true;return;}
      if(Odwiedzony[*it]==false)
	ZnajdzDrogeDFS(*it,koniec);
    }
  
}


template <typename T>
void Graf<T>::ZnajdzDrogeBFS(int start,int koniec)
{
  std::queue<T> kolejka;
  std::list<int>::iterator it=ListaSasiedztwa[start].begin();
  kolejka.push(start);
  Odwiedzony[start]=true;
  while(!kolejka.empty())
    {
      start=kolejka.front();
      kolejka.pop();
      SzukanaDroga.push_back(start);
      if(start==koniec)break;
      it=ListaSasiedztwa[start].begin();
      while(it!=ListaSasiedztwa[start].end()&&(*it!=koniec))
	{
	  if(Odwiedzony[*it])break;
	  kolejka.push(*it);
	  Odwiedzony[*it]=true;
	  ++it;
	}
    }
}

template <typename T>
void Graf<T>::print()
  {
    for(int i=0;i<ListaSasiedztwa.size();++i)
      {
	std::cout<<i<<": ";
        for (std::list<int>::iterator it=ListaSasiedztwa[i].begin(); it!=ListaSasiedztwa[i].end(); ++it)
	  {
	    std::cout<<" "<< *it;
	  }
	std::cout<<std::endl;
      }
  }

template <typename T>
void Graf<T>::printDroga()
{
  for(int i=0;i<SzukanaDroga.size();++i)
      {
	if(!(i%10))std::cout<<std::endl;
	std::cout<<SzukanaDroga[i]<<" ";
      }
}
#endif
