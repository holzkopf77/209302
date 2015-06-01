#ifndef GRAF__HH
#define GRAF__HH
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <list>
#include <queue>
#include "iObserwowany.hh"
#include "Obserwator.hh"

template <typename T>
class Graf:public iObserwowany<T>
{
public:
  std::vector<std::list<T>> ListaSasiedztwa;
  std::vector<T> SzukanaDroga;
  std::vector<bool> Odwiedzony;
  int VertexNumber;
  int RozmiarTestowanychDanych;
  long int StopCzas;
  bool znaleziony;
  std::vector<Obserwator<T>*> Obserwatorzy;

  Graf(int wierzcholki);
  void StworzLosowyGraf(int krawedzi);
  void add(int start,int koniec);
  void ZnajdzDrogeDFS(int start,int koniec);
  void CzasZnajdowaniaDrogiDFS(int start,int koniec);
  void ZnajdzDrogeBFS(int start,int koniec);
  void CzasZnajdowaniaDrogiBFS(int start,int koniec);
  void printDroga();
  //  bool find(T value);
  void print();
  void dodaj(Obserwator<T>* obserwator);
  void usun(Obserwator<T>* obserwator);
  void powiadom();
  void ZmienDaneTestowe(long int IloscTestowanychDanych, long int CzasStopu);
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
  ++RozmiarTestowanychDanych;
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
void Graf<T>::CzasZnajdowaniaDrogiDFS(int start,int koniec)
{
   std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
   ZnajdzDrogeDFS(start,koniec);
   auto elapsed = std::chrono::high_resolution_clock::now() - startTime;
   auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
   this->ZmienDaneTestowe(VertexNumber,microseconds);
   for(int i=0;i<VertexNumber;++i)Odwiedzony[i]=false;
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

      for(;it!=ListaSasiedztwa[start].end();++it)
	{
	  if(Odwiedzony[*it])continue;
	  kolejka.push(*it);
	  Odwiedzony[*it]=true;
	}

    }
}

template <typename T>
void Graf<T>::CzasZnajdowaniaDrogiBFS(int start,int koniec)
{
   std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
   ZnajdzDrogeBFS(start,koniec);
   auto elapsed = std::chrono::high_resolution_clock::now() - startTime;
   auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
   this->ZmienDaneTestowe(VertexNumber,microseconds);
   for(int i=0;i<VertexNumber;++i)Odwiedzony[i]=false;
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

template <typename T>
void Graf<T>::dodaj(Obserwator<T>* obserwator)
{
  Obserwatorzy.push_back(obserwator);
}
template <typename T>
void Graf<T>::usun(Obserwator<T>* obserwator)
{
  Obserwatorzy.pop_back();
}

template <typename T>
void Graf<T>::powiadom()
{
  for(int i=0;i<Obserwatorzy.size();++i)
    Obserwatorzy[i]->odswiez(RozmiarTestowanychDanych,StopCzas);
}

template<typename T>
void Graf<T>::ZmienDaneTestowe(long int IloscTestowanychDanych, long int CzasStopu)
{
  RozmiarTestowanychDanych=IloscTestowanychDanych;
  StopCzas=CzasStopu;
}

template<typename T>
void Graf<T>::StworzLosowyGraf(int krawedzi)
{ 
  int koniec,poczatek;
  srand(time(nullptr));
  for(int i=0;i<VertexNumber-1;++i)
    ListaSasiedztwa[i].push_front(i+1);
  ListaSasiedztwa[VertexNumber-1].push_front(0);
  for(int i=0;i<krawedzi;++i)
    {
      poczatek=std::rand()%VertexNumber;
      koniec= std::rand()%VertexNumber;
      ListaSasiedztwa[poczatek].push_front(koniec);
    }
}
#endif
