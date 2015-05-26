#include"StrukturyBenchmark.hh"
#include "Wyniki.hh"
#include "DrzewoBinTest.hh"
#include "TreeAVLTest.hh"
#define ILOSC_POW 10
#define ILOSC_PROB 10
using namespace std;
/*!
 *\file
 *\brief funkcja glowna programu
 */
int main()
{

  TreeAVLTest<int> E;
  DrzewoBinTest<int> B;
  unsigned int Tablica_Rozmiarow[] = {50,100,500,1000,5000,10000,50000,100000,500000,1000000};
  Wyniki *W = new Wyniki(ILOSC_POW,ILOSC_PROB,Tablica_Rozmiarow);
  StrukturyBenchmark<int> *S = new StrukturyBenchmark<int>(ILOSC_PROB,ILOSC_POW,Tablica_Rozmiarow);
  //S-> _Generator(10000000);
  S -> _DodajObserwator(W);
  S -> _WykonajTest(E,"Dane.dat");
  W -> _ZapiszWyniki("Wyniki.dat");
  S -> _UsunObserwator(W);  
 
  return 0;
}
