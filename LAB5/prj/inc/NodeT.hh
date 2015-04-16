template <typename Klucz, typename T>
class NodeT
{
  Klucz key;
  T value;

public:
  NodeT(const Klucz &klucz):key(klucz){};
  NodeT(){};
  Klucz& ZwrocKlucz(){
    return key;
  }
  
  T & ZwrocValue() {
        return value;
     }

  void ZmienKlucz(Klucz kluczyk)
  {
    key=kluczyk;
  }

  void ZmienValue(T Value)
  {
    value=Value;
  }


};
