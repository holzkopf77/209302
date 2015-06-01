#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "TreeZlozonosc.hh"
#include "RBTree.hh"
#include "BinaryTree.hh"
#include "Obserwator.hh"

void DodajRBTree(int rozmiar, int * daneWe,RBTree<int> *drzewo)
{
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
  for(int i=0;i<rozmiar;++i)
    drzewo->add(daneWe[i]);
  auto elapsed = std::chrono::high_resolution_clock::now() - start;
  auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
  drzewo->ZmienDaneTestowe(rozmiar,microseconds);
}

void DodajBinaryTree(int rozmiar, int * daneWe,BinaryTree<int> *drzewo)
{
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
  for(int i=0;i<rozmiar;++i)
    drzewo->add(daneWe[i]);
  auto elapsed = std::chrono::high_resolution_clock::now() - start;
  auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
  drzewo->ZmienDaneTestowe(rozmiar,microseconds);
}

void ZnajdzRBTree(int rozmiar, int * daneWe,RBTree<int> *drzewo)
{
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
  for(int i=0;i<rozmiar;++i)
    drzewo->find(daneWe[i]);
  auto elapsed = std::chrono::high_resolution_clock::now() - start;
  auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
  drzewo->ZmienDaneTestowe(rozmiar,microseconds);
}

void ZnajdzBinaryTree(int rozmiar, int * daneWe,BinaryTree<int> *drzewo)
{
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
  for(int i=0;i<rozmiar;++i)
    drzewo->find(daneWe[i]);
  auto elapsed = std::chrono::high_resolution_clock::now() - start;
  auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
  drzewo->ZmienDaneTestowe(rozmiar,microseconds);
}

void ZnajdzBinaryTreeNieIstniejacyElement(int rozmiar, int * daneWe,BinaryTree<int> *drzewo)
{
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
  drzewo->find(926);//grepem w DaneCalkowite.dat sprawdzilem, ze nie ma takiej liczby w zbiorze
  auto elapsed = std::chrono::high_resolution_clock::now() - start;
  auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
  drzewo->ZmienDaneTestowe(rozmiar,microseconds);
}

void ZnajdzRBTreeNieIstniejacyElement(int rozmiar, int * daneWe,RBTree<int> *drzewo)
{
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    drzewo->find(926);//grepem w DaneCalkowite.dat sprawdzilem, ze nie ma takiej liczby w zbiorze
  auto elapsed = std::chrono::high_resolution_clock::now() - start;
  auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
  drzewo->ZmienDaneTestowe(rozmiar,microseconds);
}

void ZbadajZlozonoscDrzew(int *dane,int IleRazy,int *rozmiar,std::ostream &OutRBadd,std::ostream &OutBIadd,std::ostream &OutRBfind,std::ostream &OutBIfind)
{
 for(int i=0;i<IleRazy;++i)
    {
      Obserwator<int> obserwator,obserwator2;
      RBTree<int> treeRB;
      BinaryTree<int> treeBinary;
      
      treeRB.dodaj(&obserwator);
      DodajRBTree(rozmiar[i],dane,&treeRB);
      treeRB.powiadom();
      obserwator.zapisz(OutRBadd);
      obserwator.clear();
  
      treeBinary.dodaj(&obserwator2);
      DodajBinaryTree(rozmiar[i],dane,&treeBinary);
      treeBinary.powiadom();
      obserwator2.zapisz(OutBIadd);
      obserwator2.clear();
     
      // ZnajdzRBTree(rozmiar[i],dane,&treeRB);
      // treeRB.powiadom();
      // obserwator.zapisz(OutRBfind);
      // obserwator.clear();
  
      // ZnajdzBinaryTree(rozmiar[i],dane,&treeBinary);
      // treeBinary.powiadom();
      // obserwator2.zapisz(OutBIfind);
      // obserwator2.clear();

      ZnajdzRBTreeNieIstniejacyElement(rozmiar[i],dane,&treeRB);
      treeRB.powiadom();
      obserwator.zapisz(OutRBfind);
      obserwator.clear();

      ZnajdzBinaryTreeNieIstniejacyElement(rozmiar[i],dane,&treeBinary);
      treeBinary.powiadom();
      obserwator2.zapisz(OutBIfind);
      obserwator2.clear();
      
    }
}


