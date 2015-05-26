#include"StrukturyBenchmark.hh"
#include "Wyniki.hh"
#include "Graf.hh"
#define ILOSC_POW 10
#define ILOSC_PROB 5
using namespace std;
/*!
 *\file
 *\brief funkcja glowna programu
 */
int main()
{
  Graf K(10);
  unsigned int Tablica_Rozmiarow[] = {100,1000,10000,100000,1000000};
  Wyniki *W = new Wyniki(ILOSC_POW,ILOSC_PROB,Tablica_Rozmiarow);
  StrukturyBenchmark<int> *S = new StrukturyBenchmark<int>(ILOSC_PROB,ILOSC_POW,Tablica_Rozmiarow);
  srand(time(NULL));
  K._DodajKrawedz(1,2);
  K._DodajKrawedz(1,3);
  K._DodajKrawedz(2,4);
  K._DodajKrawedz(3,4);
  K._DodajKrawedz(1,7);
  K.BFS(1);

  /*
  S -> _DodajObserwator(W);
  //S -> _Ustaw(O);
  //S -> _Generator();
  S -> _Wczytaj("Dane.dat","Klucze.dat");
  S -> _WykonajTest();
  W -> _ZapiszWyniki("Wyniki.dat");
  S -> _UsunObserwator(W);
  */
  return 0;
}
