#include <iostream>
#include <fstream>
#include "OperacjeNaPlikach.hh"
#include "BinaryTree.hh"
#include "RBTree.hh"
#include "TreeZlozonosc.hh"
using namespace std;

int main()
{
  int rozmiar[]={10,100,1000,10000,100000,200000};
  int maxRozmiar=1000000;
  int ileRazy=6;
  int *dane=new int[maxRozmiar];
  ofstream DodawanieRedBlack,DodawanieBinary;
  ofstream SzukanieRedblack,SzukanieBinary;
  ofstream SzukanieNieIstniejacegoRedblack,SzukanieNieIstniejacegoBinary;
  DodawanieRedBlack.open("DodawanieRedBlack.dat");
  DodawanieBinary.open("DodawanieBinary.dat");
  SzukanieRedblack.open("SzukanieRedBlack.dat");
  SzukanieBinary.open("SzukanieBinary.dat");
  SzukanieNieIstniejacegoRedblack.open("SzukanieNieIstniejacegoRedblack.dat");
  SzukanieNieIstniejacegoBinary.open("SzukanieNieIstniejacegoBinary.dat");
  
  ifstream daneCalkowite;
  daneCalkowite.open("DaneRand.dat");
  WczytajDaneZpliku(daneCalkowite,maxRozmiar,dane);
  //ZbadajZlozonoscDrzew(dane,ileRazy,rozmiar,DodawanieRedBlack,DodawanieBinary,SzukanieRedblack,SzukanieBinary);
   ZbadajZlozonoscDrzew(dane,ileRazy,rozmiar,DodawanieRedBlack,DodawanieBinary,SzukanieNieIstniejacegoRedblack,SzukanieNieIstniejacegoBinary);
}









