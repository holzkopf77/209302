#ifndef OPERACJENAPLIKACH_HH
#define OPERACJENAPLIKACH_HH

template<typename T>
std::istream& WczytajDaneZpliku(std::istream &Strm,unsigned long int IloscDanych, T* dane)
{
  for(unsigned long int i=0;i<IloscDanych;++i)
    {
      Strm>>dane[i];
    }
  return Strm;
}
#endif
