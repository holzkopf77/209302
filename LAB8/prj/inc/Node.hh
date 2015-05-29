#ifndef NODE_HH
#define NODE_HH
template <typename T>
class  Node
{
public:
  Node();
 ~ Node();
  T  val;
  Node<T> * left;
  Node<T> *right;
  Node<T> *up;
};

template <typename T>
Node<T>::Node()
  {
    left=nullptr;
    right=nullptr;
    up=nullptr;
  }


template <typename T>
Node<T>::~Node()
  {
    //delete left;
    //delete right;
    //delete up;
  }
#endif
