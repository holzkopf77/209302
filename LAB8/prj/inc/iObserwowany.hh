#ifndef IOBSERWOWANY__HH
#define IOBSERWOWANY__HH
#include "Obserwator.hh"
template <typename T>
class iObserwowany
{
public:
  virtual void dodaj(Obserwator<T>* obserwator)=0;
  virtual void powiadom()=0;
  virtual void usun(Obserwator<T>* obserwator)=0;

};
#endif
