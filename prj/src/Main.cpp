#include"StrukturyBenchmark.hh"
#include "Wyniki.hh"
#include "Graf.hh"

const unsigned int ILOSC_POW = 10;
const unsigned int ILOSC_PROB = 7;

//************************************************************
/*!
 *\file
 *\brief funkcja glowna programu
 */
//************************************************************

int main()
{
  unsigned int Tablica_Rozmiarow[] = {50,100,500,1000,5000,10000,20000};
  Wyniki *W = new Wyniki(ILOSC_POW,ILOSC_PROB,Tablica_Rozmiarow);
  StrukturyBenchmark<int> *S = new StrukturyBenchmark<int>(ILOSC_PROB,ILOSC_POW,Tablica_Rozmiarow);
  S -> _DodajObserwator(W);

  for(unsigned int i = 0;i < ILOSC_PROB; ++i)
    {
      Graf<int> K(Tablica_Rozmiarow[i]);
      K._Zaladuj(Tablica_Rozmiarow[i]);
      S -> _WykonajTest(K,Tablica_Rozmiarow[i]);
    }

    W -> _ZapiszWyniki("Wyniki.dat");
    S -> _UsunObserwator(W);
  return 0;
}
