#include"StrukturyBenchmark.hh"
#include "Wyniki.hh"
#include "Graf.hh"

#define ILOSC_POW 100
#define ILOSC_PROB 2
using namespace std;
/*!
 *\file
 *\brief funkcja glowna programu
 */
int main()
{
  const unsigned int Tablica_Rozmiarow[] = {100,500,1000,5000,10000,50000};
  Wyniki *W = new Wyniki(ILOSC_POW,ILOSC_PROB,Tablica_Rozmiarow);
  StrukturyBenchmark<int> *S = new StrukturyBenchmark<int>(ILOSC_PROB,ILOSC_POW,Tablica_Rozmiarow);
  S -> _DodajObserwator(W);
  for(int i = 0; i < ILOSC_PROB; ++i)
    {
      Graf K(Tablica_Rozmiarow[i]);
      K._Zaladuj(Tablica_Rozmiarow[i]);
      S -> _WykonajTest(K);
    }
  W -> _ZapiszWyniki("Wyniki.dat");
  S -> _UsunObserwator(W);

  return 0;
}
