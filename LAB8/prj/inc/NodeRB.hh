#ifndef NODERB_HH
#define NODERB_HH
template <typename T>
class  NodeRB
{
public:
  NodeRB();
  ~ NodeRB();
  T  val;
  NodeRB<T> * left;
  NodeRB<T> *right;
  NodeRB<T> *up;
  bool czerwony;
};

template <typename T>
NodeRB<T>::NodeRB()
  {
    left=nullptr;
    right=nullptr;
    up=nullptr;
    czerwony=true;
  }


template <typename T>
NodeRB<T>::~NodeRB()
  {
    //delete left;
    //delete right;
    //delete up;
  }
#endif
