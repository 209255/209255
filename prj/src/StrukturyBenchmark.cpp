#include "StrukturyBenchmark.hh"
using namespace std;
//***********************************************************************************
StrukturyBenchmark::StrukturyBenchmark (unsigned int Proby,unsigned int Powt,
				       unsigned int *Rozmiary) 
{
  _IloscProb = Proby;
  _IloscPowt = Powt;
  _TablicaRozmiarow = new unsigned int[_IloscProb];
  _Wartosci = new int[ILOSC];
  _Klucze = new std::string[ILOSC];

  for(unsigned int i = 0; i < _IloscProb; ++i){
    _TablicaRozmiarow[i] = Rozmiary[i];}
  
  for (unsigned int i = 0; i < ILOSC; ++i){
	_Wartosci[i] = 0;
	_Klucze[i] = 'a';}
}
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
void StrukturyBenchmark:: _Wczytaj(string PlikWart,string PlikKlucz)
  {
    ifstream Plik_Wart;
    ifstream Plik_Klucz;
    int Temp;
    string Temp_K;
    Plik_Wart.open(PlikWart.c_str(),ios::in);
    Plik_Klucz.open(PlikKlucz.c_str(),ios::in);
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
void StrukturyBenchmark::_DodajObserwator(IObserwator *O)
{
  Obserwatorzy.push_back(O);
}
//*********************************************************************************  
void StrukturyBenchmark::_UsunObserwator(IObserwator *O)
{
  Obserwatorzy.remove(O);
}
//*********************************************************************************  
void StrukturyBenchmark::_PowiadomObserwatorow()
{
  std::list<IObserwator *>::iterator it;
  for(it = Obserwatorzy.begin(); it != Obserwatorzy.end(); ++it)
    (*it) -> _Aktualizuj();
}
//********************************************************************************* 
void StrukturyBenchmark:: _WykonajTest()
{
  for (unsigned int i = 0; i < _IloscProb; ++i)
    {
      for(unsigned int j = 0; j < _IloscPowt; ++j)
	{
	  this -> _Zaladuj(_TablicaRozmiarow[i]);
	  this -> _PowiadomObserwatorow();
	  this -> _Test(_TablicaRozmiarow[i]);
	  this -> _PowiadomObserwatorow();
	  this -> _Zwolnij();
	}
    }
}
//*******************************************************************************
