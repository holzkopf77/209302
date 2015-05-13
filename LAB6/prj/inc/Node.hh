#ifndef NODE_HH
#define NODE_HH
template <typename T>
class  Node
{
public:
  T  val;
  Node<T> * next;
};
#endif
