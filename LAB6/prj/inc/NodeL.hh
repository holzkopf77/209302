#ifndef NODEL__HH
#define NODEL__HH

template<typename T>
class  NodeL
{
public:
  T val;
  NodeL<T> *prev;
  NodeL<T> * next;
};
#endif
