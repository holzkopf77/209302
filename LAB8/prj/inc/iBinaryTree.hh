#ifndef IBINARYTREE__HH
#define IBINARYTREE__HH

template <typename T>
class iBinaryTree
{
public:
  virtual void add(T value)=0;
  virtual bool find(T value)=0;
  virtual void print()=0;
};

#endif
