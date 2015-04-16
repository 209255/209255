#include "StrukturyBenchmark.hh"
using namespace std;
//***********************************************************************************
void StrukturyBenchmark:: _Test(const unsigned int n) const 
  {
    for(unsigned int i = 0; i < n; ++i) 
      W -> operator()(_Klucze[i]);
  }
//***********************************************************************************
void StrukturyBenchmark:: _Zaladuj(const unsigned int n ) const
  {
    for(unsigned int i = 0; i < n; ++i)
      W -> operator[](_Klucze[i]) = _Wartosci[i];
  }
//***********************************************************************************
void StrukturyBenchmark:: Przydziel()
  {
    _Wartosci = new int[ILOSC];
    _Klucze = new std::string[ILOSC];
    for (unsigned int i = 0; i < ILOSC; ++i)
      {
	_Wartosci[i] = 0;
	_Klucze[i] = 'a';
      }
  }
//***********************************************************************************
void StrukturyBenchmark:: _Wczytaj(string PlikWart,string PlikKlucz)
  {
    ifstream Plik_Wart(PlikWart);
    ifstream Plik_Klucz(PlikKlucz);
    int Temp;
    string Temp_K;
    Przydziel();
    if(!Plik_Wart || !Plik_Klucz)
      {
      std::cerr << "Blad przy otwieraniu Pliku: " 
		<< std::endl;exit(1);
      }
    else
      {
	for( int i = 0;i < ILOSC ; ++i)
	  {
	    Plik_Wart >> Temp;
	    if(Plik_Wart.eof())
	      {
		std::cout << "Napotkany EOF przed wczytaniem wszytskich danych"
			  << std::endl;
	      }
	    _Wartosci[i] = Temp;
	  }
	
	for( int i = 0;i < ILOSC; ++i)
	  {
	    Plik_Klucz >> Temp_K;
	    if(Plik_Klucz.eof())
	      {
		std::cout << "Napotkany EOF przed wczytaniem wszytskich danych"
			  << std::endl;
	      }
	    _Klucze[i] = Temp_K;
	  }
      }
   }
//***********************************************************************************
