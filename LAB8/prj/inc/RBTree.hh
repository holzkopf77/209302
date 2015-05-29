#ifndef RBTREE__HH
#define RBTREE__HH
#include "NodeRB.hh"
#include "iRBTree.hh"
#include "iObserwowany.hh"
#include <queue>
#include <vector>
#include <iostream>

template <typename T>
class RBTree:public iRBTree<T>, public iObserwowany<T>
{
public:
  std::vector<Obserwator<T>*> Obserwatorzy;
  NodeRB<T> *root;
  NodeRB<T> S;
  int size;
  long int RozmiarTestowanychDanych;
  long int StopCzas;

  RBTree();
  ~RBTree();
  
  void add(T value);
  bool find(T value);
  void print();
  
  void InitialPositionOfLeaf(NodeRB<T> *Z, T value);
  void SolutionThreeCases(NodeRB<T> *Z);
  void rotate_L(NodeRB<T> *Z);
  void rotate_R(NodeRB<T> *Z);
  void DFSRelease(NodeRB<T> * p);

  void dodaj(Obserwator<T>* obserwator);
  void powiadom();
  void usun(Obserwator<T> *obserwator);
  void ZmienDaneTestowe(long int IloscTestowanychDane, long int CzasStopu);
};

template <typename T>
RBTree<T>::RBTree():root()
  {
    S.czerwony=false;
    S.up=&S;
    S.left=&S;
    S.right=&S;
    root=&S;
    RozmiarTestowanychDanych=0;
    StopCzas=0;
    size=0;
  }

template <typename T>
RBTree<T>::~RBTree()
  {
    DFSRelease(root); 
  }

template <typename T>
bool RBTree<T>::find(T value)
  {
    NodeRB<T> *p =root;
    bool znaleziono=false;
    while(p!=&S)
      {
	if(p->val==value){znaleziono=true;break;}
	if(p->val>=value)p=p->left;
	else p=p->right;
      }
    return znaleziono;
  }

template <typename T>
void RBTree<T>::print()
  {
    std::queue<NodeRB<T>*> DaneDrzewa;
    NodeRB<T> *v;
    DaneDrzewa.push(root);
    while(!DaneDrzewa.empty())
      {
	v=DaneDrzewa.front();
	std::cout<<v->val<<std::endl;
	DaneDrzewa.pop();
	if(v->left!=&S)DaneDrzewa.push(v->left);
	if(v->right!=&S)DaneDrzewa.push(v->right);
      }
  }

template <typename T>
void RBTree<T>::add(T value)
{
  NodeRB<T> * X;
  X = new NodeRB<T>;
  this->InitialPositionOfLeaf(X,value); //dodany wezel czerwony, miejsce poczatkowe
  this->SolutionThreeCases(X);//if drzewo zaburzone, rozwaz 3 przypadki i napraw
  ++size;
}


template <typename T>
void RBTree<T>::rotate_L(NodeRB<T> *Z)
{
  NodeRB<T> * B, * p;

  B = Z->right;
  if(B != nullptr)
  {
    p = Z->up;
    Z->right = B->left;
    if(Z->right != nullptr) Z->right->up = Z;

    B->left = Z;
    B->up = p;
    Z->up = B;

    if(p != nullptr)
    {
      if(p->left == Z) p->left = B; else p->right = B;
    }
    else root = B;
  }
}

template <typename T>
void RBTree<T>::rotate_R(NodeRB<T> *Z)
{
  NodeRB<T> *B,*p;
  B=Z->left;
  if(B != nullptr)
  {
    p = Z->up;
    Z->left = B->right;
    if(Z->left != nullptr) Z->left->up = Z;

    B->right = Z;
    B->up = p;
    Z->up = B;

    if(p != nullptr)
    {
      if(p->left == Z) p->left = B; else p->right = B;
    }
    else root = B;
  }
}

template <typename T>
void RBTree<T>::DFSRelease(NodeRB<T> * p)
{
  if(p != &S)
  {
    DFSRelease(p->left);   // usuwamy lewe poddrzewo
    DFSRelease(p->right);  // usuwamy prawe poddrzewo
    delete p;              // usuwamy sam węzeł
  }
}

template <typename T>
void RBTree<T>::InitialPositionOfLeaf(NodeRB<T> *X, T value)
{
  X->left  = &S;          // Inicjujemy pola
  X->right = &S;
  X->up    = root;
  X->val   = value;
  if(X->up == &S) root = X; // X staje się korzeniem
  else
  while(true)             // Szukamy liścia do zastąpienia przez X
  {
    if(value < X->up->val)
    {
      if(X->up->left == &S)
      {
        X->up->left = X;  // X zastępuje lewy liść
        break;
      }
      X->up = X->up->left;
    }
    else
    {
      if(X->up->right == &S)
      {
        X->up->right = X; // X zastępuje prawy liść
        break;
      }
      X->up = X->up->right;
    }
  }
  X->czerwony = true;         // Węzeł kolorujemy na czerwono
}

template <typename T>
void RBTree<T>::SolutionThreeCases(NodeRB<T> *X)
{
  NodeRB<T> * Y;
   while((X != root) && (X->up->czerwony))//sprawdzenie czy drzewo jest zaburzone
  {
    if(X->up == X->up->up->left)
    {
      Y = X->up->up->right; // Y -> wujek X

      if(Y->czerwony)  // Przypadek 1
	{
	  X->up->czerwony = false;
	  Y->czerwony = false;
	  X->up->up->czerwony = true;
	  X = X->up->up;
	  continue;
	}

      if(X == X->up->right) // Przypadek 2
	{
	  X = X->up;
	  rotate_L(X);
	}

      X->up->czerwony = false; // Przypadek 3
      X->up->up->czerwony = true;
      rotate_R(X->up->up);
      break;
    }
    else
    {                  // Przypadki lustrzane
      Y = X->up->up->left;

      if(Y->czerwony) // Przypadek 1
      {
        X->up->czerwony = false;
        Y->czerwony = false;
        X->up->up->czerwony = true;
        X = X->up->up;
        continue;
      }

      if(X == X->up->left) // Przypadek 2
      {
        X = X->up;
        rotate_R(X);
      }

      X->up->czerwony = false; // Przypadek 3
      X->up->up->czerwony = true;
      rotate_L(X->up->up);
      break;
    }
  }
   root->czerwony = false;
}

template <typename T>
void RBTree<T>::dodaj(Obserwator<T>* obserwator)
{
  Obserwatorzy.push_back(obserwator);
}
template <typename T>
void RBTree<T>::usun(Obserwator<T>* obserwator)
{
  Obserwatorzy.pop_back();
}

template <typename T>
void RBTree<T>::powiadom()
{
  for(int i=0;i<Obserwatorzy.size();++i)
      Obserwatorzy[i]->odswiez(RozmiarTestowanychDanych,StopCzas);
}

template<typename T>
void RBTree<T>::ZmienDaneTestowe(long int IloscTestowanychDanych, long int CzasStopu)
{
  RozmiarTestowanychDanych=IloscTestowanychDanych;
  StopCzas=CzasStopu;
}
#endif





