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
  DodawanieRedBlack.open("DodawanieRedBlack.dat");
  DodawanieBinary.open("DodawanieBinary.dat");
  SzukanieRedblack.open("SzukanieRedBlack.dat");
  SzukanieBinary.open("SzukanieBinary.dat");
  
  ifstream daneCalkowite;
  daneCalkowite.open("daneCalkowite.dat");
  WczytajDaneZpliku(daneCalkowite,maxRozmiar,dane);
  ZbadajZlozonoscDrzew(dane,ileRazy,rozmiar,DodawanieRedBlack,DodawanieBinary,SzukanieRedblack,SzukanieBinary);
}









