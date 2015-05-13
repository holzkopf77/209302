#ifndef IKONTENERY__HH
#define IKONTENERY__HH
template<typename T>
class iKontenery
{
public:
  virtual void push( T value)=0;
  virtual void pop()=0;
};
#endif
