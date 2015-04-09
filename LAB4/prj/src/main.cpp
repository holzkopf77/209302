#include <iostream>
#include <fstream>
#include <string>
#include "Benchmark.hh"
#include "ZapiszStosKolejkaLista.hh"
#include "OperacjeNaPlikach.hh"
#include "Struktury.hh"
using namespace std;

void quicksort(int *tablica, int lewy, int prawy);
void ObudowaQuickSort(int *tablica,int rozmiar);
void quicksortLista(List<int> *list, NodeL<int> *h,NodeL<int> *t);
void Ob(List<int> *list,int rozmiar);

int main()
{

  List<int> *lista=new List<int>;
  
  long int  IloscLiczb=30;
  //int *dane= new int[IloscLiczb];
  ifstream plikwe;
  ofstream plikwyStosu,plikwyKolejki,plikwyListy;
  plikwe.open("daneCalkowite.dat");
  plikwyStosu.open("wynikiStosu.dat");
  plikwyListy.open("wynikiListy.dat");
  plikwyKolejki.open("wynikiKolejki.dat");
  //  WczytajDaneZpliku(plikwe,IloscLiczb,dane);
  cout<<"andrzej"<<endl;
  for(int i=0;i<IloscLiczb;++i)
    {
      int a;plikwe>>a;
      lista->push_front(a);
    }
  lista->show();
  Ob(lista,IloscLiczb-1);
  cout<<endl;
  lista->show();
  /*Benchmark<int> ben(1,IloscLiczb,dane);
  try{
    ben.Testuj(IloscLiczb,&ObudowaQuickSort);
    ben.ZapiszWynikiZlozonosciObliczeniowej(plikwyStosu);
    delete [] dane;
  }
  catch(string ostrzezenie)
  {cout<<ostrzezenie<<endl;}*/
}



void ObudowaQuickSort(int *tablica,int rozmiar)
{
  int lewy=0;
  int prawy=rozmiar-1;
  quicksort(tablica,lewy,prawy);
}
void quicksort(int *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while(tablica[i]<v) i++;
        while(tablica[j]>v) j--;
        if(i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>lewy) quicksort(tablica,lewy, j);
    if(i<prawy) quicksort(tablica, i, prawy);
}

void Ob(List<int> *list,int rozmiar)
{
  int lewy=0;
  int prawy=rozmiar-1;
  quicksortLista(list,lewy,prawy);
}

void quicksortLista(List<int> *list,int lewy,int prawy)
{
   int v=list[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while(tablica[i]<v) i++;
        while(tablica[j]>v) j--;
        if(i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>lewy) quicksort(tablica,lewy, j);
    if(i<prawy) quicksort(tablica, i, prawy);
}
