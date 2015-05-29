#ifndef BINARYTREE__HH
#define BINARYTREE__HH
#include "Node.hh"
#include "iBinaryTree.hh"
#include <queue>
#include <vector>
#include "iObserwowany.hh"

template <typename T>
class BinaryTree:public iBinaryTree<T>, public iObserwowany<T>
{
public:
  Node<T> *root;
  int size;
  long int RozmiarTestowanychDanych;
  long int StopCzas;
   std::vector<Obserwator<T>*> Obserwatorzy;

  BinaryTree();
  ~BinaryTree();
  void add(T value);
  bool find(T value);
  void print();

  void dodaj(Obserwator<T>* obserwator);
  void powiadom();
  void usun(Obserwator<T> *obserwator);
  void ZmienDaneTestowe(long int IloscTestowanychDane, long int CzasStopu);
};

template <typename T>
BinaryTree<T>::BinaryTree():root()
  {
    root=nullptr;
    RozmiarTestowanychDanych=0;
    StopCzas=0;
    size=0;
  }

template <typename T>
BinaryTree<T>::~BinaryTree()
  {
    std::vector<Node<T>*> DaneDrzewa;
    DaneDrzewa.push_back(root);
    Node<T> *v=root;
    for (int i=0; i < size; ++i) 
      {
	v=DaneDrzewa[i];
	if(v->left!=nullptr)DaneDrzewa.push_back(v->left);
	if(v->right!=nullptr)DaneDrzewa.push_back(v->right);
      }
    for(int i=size-1;i>0;--i)
	delete DaneDrzewa[i];
    DaneDrzewa.clear();
  }

template <typename T>
void BinaryTree<T>::add(T value)
  {
    Node<T> *p,*n,*last;
    bool prawy=false; //czyli lewa gałąź
    n=new Node<T>;
    n->val=value;
    p=root;
    if(p!=nullptr)
      {
	do
	  {
	    last=p;
	    if(p->val>=value){p=p->left;prawy=false;}
	    else {p=p->right;prawy=true;}
	  }
	while(p!=nullptr);
	if(prawy)last->right=n;
	else last->left=n;
      }
    else{root=n;}
    ++size;
  }

template <typename T>
void BinaryTree<T>::print()
  {
    std::queue<Node<T>*> DaneDrzewa;
    Node<T> *v;
    DaneDrzewa.push(root);
    while(!DaneDrzewa.empty())
      {
	v=DaneDrzewa.front();
	std::cout<<v->val<<std::endl;
	DaneDrzewa.pop();
	if(v->left!=nullptr)DaneDrzewa.push(v->left);
	if(v->right!=nullptr)DaneDrzewa.push(v->right);
      }
  }

template <typename T>
bool BinaryTree<T>::find(T value)
  {
    Node<T> *p =root;
    bool znaleziono=false;
    while(p!=nullptr)
      {
	if(p->val==value){znaleziono=true;break;}
	if(p->val>=value)p=p->left;
	else p=p->right;
      }
    return znaleziono;
  }

template <typename T>
void BinaryTree<T>::dodaj(Obserwator<T>* obserwator)
{
  Obserwatorzy.push_back(obserwator);
}
template <typename T>
void BinaryTree<T>::usun(Obserwator<T>* obserwator)
{
  Obserwatorzy.pop_back();
}

template <typename T>
void BinaryTree<T>::powiadom()
{
  for(int i=0;i<Obserwatorzy.size();++i)
      Obserwatorzy[i]->odswiez(RozmiarTestowanychDanych,StopCzas);
}

template<typename T>
void BinaryTree<T>::ZmienDaneTestowe(long int IloscTestowanychDanych, long int CzasStopu)
{
  RozmiarTestowanychDanych=IloscTestowanychDanych;
  StopCzas=CzasStopu;
}

#endif
