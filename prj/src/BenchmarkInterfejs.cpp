#include "BenchmarkInterfejs.hh"
#include <sys/time.h>
#include <iostream>
#include <fstream>
using namespace std;
//************************************************************************************************
/*!
 *\file 
 *\brief Definicje Metod klasy BenchmarkInterfejs
 */
//************************************************************************************************

//************************************************************************************************
void BenchmarkInterfejs:: _WykonajTest(const unsigned int Ilosc_Pow) const
{
  double Wynik = 0;
  unsigned int Tablica_Rozmiarow[] = {100,1000,10000,100000,100000};
   for (unsigned int i = 0; i < ( sizeof(Tablica_Rozmiarow) / sizeof(unsigned int) ); ++i)
     {
     cout << "Pracuje nad " << Tablica_Rozmiarow[i] << " Danych : " << endl;
      for(unsigned int j = 0; j < Ilosc_Pow; ++j)
       {
	 clock_t Start = clock();
	 this -> _Test(Tablica_Rozmiarow[i]);
	 clock_t Koniec = clock();
	 Wynik += ((Koniec - Start)/ (double)
		   (CLOCKS_PER_SEC / 1000)) ;
	 this -> _Zwolnij(Tablica_Rozmiarow[i]);
       }
      cout << Wynik/Ilosc_Pow << endl;
   }
}
//*******************************************************************************
void BenchmarkInterfejs:: _Generator(string Plikout, const int n)const
{
  fstream Plik;
  srand(time (NULL));
  Plik.open(Plikout.c_str(),ios::out);
  if(Plik.good())
    {
      for( int i = 0 ; i < n; ++i)
	Plik << rand()%100 << endl;
    }
  else
    {
      cerr << "Blad utworzenia pliku!" << endl; exit(1);
    }
}
//*********************************************************************************  
