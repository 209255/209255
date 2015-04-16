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
void BenchmarkInterfejs:: _WykonajTest(const unsigned int Ilosc_Pow)
{
  double Wynik = 0;
  const unsigned int Tablica_Rozmiarow[] = {10,100,1000,10000,100000,1000000};
 
   for (unsigned int i = 0; i < ( sizeof(Tablica_Rozmiarow) / sizeof(unsigned int) ); ++i)
     {
       this -> _Zaladuj(Tablica_Rozmiarow[i]);
       Wynik = 0;
       cout << "Pracuje nad " << Tablica_Rozmiarow[i] 
	    << " Danych : "   << endl;
      for(unsigned int j = 0; j < Ilosc_Pow; ++j)
       {
	 clock_t Start = clock();
	 this -> _Test(Tablica_Rozmiarow[i]);
	 clock_t Koniec = clock();
	 Wynik += (((Koniec - Start)/ (double)
		    (CLOCKS_PER_SEC / 1000)))/Tablica_Rozmiarow[i];
       }
      cout << Wynik/Ilosc_Pow << endl;
   }
}
//*******************************************************************************
void BenchmarkInterfejs:: _Generator()const
{
  fstream PlikWy;
  fstream Klucze;
  string Klucz;
  srand(time (NULL));

  PlikWy.open("Dane.dat",ios::out);
  if(PlikWy.good())
    {
      for( int i = 0 ; i < ILOSC; ++i)
	PlikWy << rand() % 100 << endl;
    }
  else
    {
      cerr << "Blad utworzenia pliku!" << endl; exit(1);
    }
  PlikWy.close();

  Klucze.open("Klucze.dat",ios::out);
  if(Klucze.good())
    {
      for(unsigned int i = 0; i < ILOSC; ++i)
	{
	  Klucz.clear();
	  for( int i = 0 ; i < DLUGOSC_SLOWA; ++i)
	    Klucz+= ('a' + rand() % 25);
	  Klucze << Klucz << ' ';
	}
    }
  else
    {
      cerr << "Blad utworzenia pliku!" << endl; exit(1);
    }
  Klucze.close();
}
//*********************************************************************************  
