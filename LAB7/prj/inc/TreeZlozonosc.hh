#ifndef TREEZLOZONOSC__HH
#define TREEZLOZONOSC__HH
#include "RBTree.hh"
#include "BinaryTree.hh"
//#include <fstream>
void DodajRBTree(int rozmiar, int * daneWe,RBTree<int> *drzewo);
void DodajBinaryTree(int rozmiar, int * daneWe,BinaryTree<int> *drzewo);
void ZnajdzRBTree(int rozmiar, int * daneWe,RBTree<int> *drzewo);
void ZnajdzBinaryTree(int rozmiar, int * daneWe,BinaryTree<int> *drzewo);
void ZbadajZlozonoscDrzew(int *dane,int IleRazy,int *rozmiar,std::ostream &OutRBadd,std::ostream &OutBIadd, std::ostream &OutRBfind,std::ostream &OutBIfind);
void ZnajdzBinaryTreeNieIstniejacyElement(int rozmiar, int * daneWe,BinaryTree<int> *drzewo);
void ZnajdzRBTreeNieIstniejacyElement(int rozmiar, int * daneWe,RBTree<int> *drzewo);
#endif
