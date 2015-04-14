#include"StosTab.hh"
#include"StrukturyBenchmark.hh"
#include "TablicaAso.hh"
#define ILOSC_DANYCH 100000000
using namespace std;
/*!
 *\file
 *\brief funkcja glowna programu
 */
int main(int argc,char *argv[])
{
  TablicaAso O;

  O["Napis"] = 10;
  O["marzena"] = 90;
  O["mazrena"] = 9;
  
  cout << O["Napis"] << endl;
  cout << O("marzena")  << endl;
  cout << O("mazrena")  << endl;
  cout << O("marzean")  << endl;
 
  return 0;
}
