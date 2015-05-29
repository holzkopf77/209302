#include <iostream>
#include "Graf.hh"
#include <list>
#include <vector>
using namespace std;

int main()
{
  Graf<int> graf(5);
  graf.add(0,1);
  graf.add(1,2);
  graf.add(2,3);
  graf.add(3,4);
  graf.add(4,0);
  graf.add(0,3);
  graf.print();
  cout<<endl<<endl;
  graf.ZnajdzDrogeBFS(0,0);
  graf.printDroga();
}









