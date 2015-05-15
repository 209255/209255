#include"StosTab.hh"
#include"StrukturyBenchmark.hh"
#include "Wyniki.hh"
#include "DrzewoBin.hh"
#define ILOSC_POW 10
#define ILOSC_PROB 5
using namespace std;
/*!
 *\file
 *\brief funkcja glowna programu
 */
int main()
{
  DrzewoBin B;
  unsigned int Tablica_Rozmiarow[] = {100,1000,10000,100000,1000000};
  Wyniki *W = new Wyniki(ILOSC_POW,ILOSC_PROB,Tablica_Rozmiarow);
  StrukturyBenchmark *S = new StrukturyBenchmark(ILOSC_PROB,ILOSC_POW,Tablica_Rozmiarow);
  S -> _DodajObserwator(W);
  //S -> _Ustaw(O);
  //S -> _Generator();
  S -> _Wczytaj("Dane.dat","Klucze.dat");
  S -> _WykonajTest();
  W -> _ZapiszWyniki("Wyniki.dat");
  S -> _UsunObserwator(W);
 
  return 0;
}
