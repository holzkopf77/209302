#include <string>
#include <iostream>
#include "Struktury.hh"
#include "ZapiszStosKolejkaLista.hh"

void ZapiszKolejnoLiczbyStosu(double* Gausowe,int size)
{
  Stack<double> stos(1);
  for(long int i=0;i<size;++i)
    stos.push(Gausowe[i]);
}

void ZapiszKolejnoLiczbyListy(double* Gausowe,int size)
{
  List<double> lista;
  for(long int i=0;i<size;++i)
    lista.push_front(Gausowe[i]);
}

void ZapiszKolejnoLiczbyKolejki(double* Gausowe,int size)
{
  Kolejka<double> kolejeczka;
  for(long int i=0;i<size;++i)
    kolejeczka.push_front(Gausowe[i]);
}
