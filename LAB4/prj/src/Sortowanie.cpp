#include "Sortowanie.hh"

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
  NodeL<int> *h=list->head;
  NodeL<int> *t=list->tail;
  quicksortLista2(list,list->head,list->tail,0,rozmiar-1);
  list->head=h;
  list->tail=t;
}

void quicksortLista(List<int> *tablica,int lewy,int prawy)
{
  int v=(*tablica)[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    NodeL<int> *left=tablica->head;
    for(int a=0;a<lewy;++a)left=left->next;
    
    NodeL<int> *right=tablica->head;
    for(int a=0;a<prawy;++a)right=right->next;
    do
    {
      while((left->val)<v) {++i;left=left->next;}
      while((right->val)>v){ --j;right=right->prev;}
        if(i<=j)
        {
	  x=left->val;
	  left->val=right->val;
	  right->val=x;
            ++i;
            --j;
        }
    }
    while(i<=j);
    if(j>lewy) quicksortLista(tablica,lewy, j);
    if(i<prawy) quicksortLista(tablica, i, prawy);
}

void quicksortLista2(List<int> *tablica,NodeL<int> *lewy,NodeL<int>*prawy,int indexLewy,int indexPrawy)
{
  int v=(*tablica)[(indexLewy+indexPrawy)/2];
  int x;
  int l=indexLewy;
  int p=indexPrawy;
    NodeL<int> *i=lewy;
    NodeL<int> *j=prawy;
    do
    {
      while((i->val)<v) {i=i->next;++indexLewy;}
      while((j->val)>v){ j=j->prev;--indexPrawy;}
        if(indexLewy<=indexPrawy)
        {
	  x=i->val;
	  i->val=j->val;
	  j->val=x;
	  i=i->next;++indexLewy;
	  j=j->prev;--indexPrawy;
        }
    }
    while(indexLewy<=indexPrawy);
    if(indexPrawy>l) quicksortLista2(tablica,lewy, j,l,indexPrawy);
    if(indexLewy<p) quicksortLista2(tablica, i, prawy,indexLewy,p);//const prawy,p
}
