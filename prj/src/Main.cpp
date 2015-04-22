#include"StosTab.hh"
#include "TablicaAso.hh"
#include"StrukturyBenchmark.hh"
#define ILOSC_POW 10
using namespace std;
/*!
 *\file
 *\brief funkcja glowna programu
 */
int main(int argc,char *argv[])
{
  TablicaAso O;
  StrukturyBenchmark S;
  S._Ustaw(O);
  //S._Generator();
  S._Wczytaj("Dane.dat","Klucze.dat");
  S._WykonajTest(ILOSC_POW);
 
  return 0;
}
