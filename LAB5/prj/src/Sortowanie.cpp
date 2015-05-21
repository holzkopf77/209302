#include "Sortowanie.hh"

/*!
 * Funkcja sortuje tablice typu int pomoca algorytmu quicksort
 * \param[] tablica - typ int*, wskaznik na tablice do posortowania
 * \param[] lewy - typ int, lewy indeks tablicy
 * \param[] prawy - typ int, prawy indeks tablicy
 */
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

/*!
 * brief  Funkcja obudowuje funkcje quicksort, zeby mogla zostac wczytana przez klase Benchmark
 * \param[] tablica - typ int*, wskaznik na tablice do posortowania
 * \param[] rozmiar - typ int, ilosc elementow do posortowania zaczynajac od indeksu 0
 */
void ObudowaQuickSort(int *tablica,int rozmiar)
{
  int lewy=0;
  int prawy=rozmiar-1;
  quicksort(tablica,lewy,prawy);
}

/*!
 * Funkcja sortuje Liste skladajaca sie z elementow typu int za pomoca algorytmu quicksort
 * \param[] tablica - typ List<int>*, wskaznik na Liste do posortowania
 * \param[] lewy - NodeL<int> * ,wskaznik na lewy wezel Listy
 * \param[] prawy - NodeL<int> *, wskaznik na prawy wezel Listy
 */
void quicksortLista(List<int> *tablica,NodeL<int> *lewy,NodeL<int>*prawy,int indexLewy,int indexPrawy)
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
    if(indexPrawy>l) quicksortLista(tablica,lewy, j,l,indexPrawy);
    if(indexLewy<p) quicksortLista(tablica, i, prawy,indexLewy,p);//const prawy,p
}

/*!
 * brief  Funkcja obudowuje funkcje quicksort, zeby mogla zostac wczytana przez klase Benchmark
 * \param[] list - typ List<int>*, wskaznik na liste do posortowania
 * \param[] rozmiar - typ int, ilosc elementow do posortowania zaczynajac od poczatku listy
 */
void Ob(List<int> *list,int rozmiar)
{
  NodeL<int> *h=list->head;
  NodeL<int> *t=list->tail;
  quicksortLista(list,list->head,list->tail,0,rozmiar-1);
  list->head=h;
  list->tail=t;
}

/*!
 * brief Funkcja scala dwa zbiory liczb rosnaca, jest funkcja skladowa MergeSortowanie
 * \param[] tab- typ Stack<int> *, wskaznik na tablice do scalenia
 * \param[] lewy - typ int, indeks poczatku lewej podtablicy
 * \param[] srodek -typ int, indeks konca lewj podtablicy
 * \param[] prawy - typ int, indeks konca prawej podtablicy
 */
void Merging(Stack<int> *tab, int lewy, int srodek, int prawy) 
{
  int i, j;
  Stack<int> pom(prawy+1);
  //zapisujemy lewą częsć podtablicy w tablicy pomocniczej
  for(i = srodek + 1; i>lewy; i--) 
    pom[i-1] = (*tab)[i-1]; 
 
  //zapisujemy prawą częsć podtablicy w tablicy pomocniczej
  for(j = srodek; j<prawy; j++) 
    pom[prawy+srodek-j] = (*tab)[j+1]; 
 
  //scalenie dwóch podtablic pomocniczych i zapisanie ich 
  //we własciwej tablicy
  for(int k=lewy;k<=prawy;k++) 
    if(pom[j]<pom[i])
      (*tab)[k] = pom[j--];
    else
      (*tab)[k] = pom[i++];
}

/*!
 * brief Funkcja sortuje tablice skladajaca sie z elementow typu int za pomoca algorytmu Scalania
 * \param[] tab- typ Stack<int> *, wskaznik na tablice do posortowania
 * \param[] lewy - typ int, indeks poczatku lewej podtablicy
 * \param[] prawy - typ int, indeks konca prawej podtablicy
 */
void MergeSortowanie(Stack<int> *tab,int lewy, int prawy)
{
  //gdy mamy jeden element, to jest on już posortowany
  if(prawy<=lewy) return; 
 
  //znajdujemy srodek podtablicy
  int srodek = (prawy+lewy)/2;
 
  //dzielimy tablice na częsć lewą i prawa
  MergeSortowanie(tab, lewy, srodek); 
  MergeSortowanie(tab, srodek+1, prawy);
 
  //scalamy dwie już posortowane tablice
  Merging(tab, lewy, srodek, prawy);
}


