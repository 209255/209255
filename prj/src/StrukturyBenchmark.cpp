#include "StrukturyBenchmark.hh"
using namespace std;
//***********************************************************************************
StrukturyBenchmark::StrukturyBenchmark (unsigned int Proby,unsigned int Powt,
				       unsigned int *Rozmiary) 
{
  _IloscProb = Proby;
  _IloscPowt = Powt;
  _TablicaRozmiarow = new unsigned int[_IloscProb];
  _IloscDanych = Rozmiary[_IloscProb-1];
  _Wartosci = new int[_IloscDanych];
  _Klucze = new string[_IloscDanych];

  for(unsigned int i = 0; i < _IloscProb; ++i){
    _TablicaRozmiarow[i] = Rozmiary[i];}
  
  for (unsigned int i = 0; i < _IloscDanych; ++i){
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
void StrukturyBenchmark:: _Wczytaj(string PlikWart)
  {
    ifstream Plik_Wart;
    int Temp;
    string Temp_K;
    Plik_Wart.open(PlikWart.c_str(),ios::in);

    if(!Plik_Wart )
      {
      std::cerr << "Blad przy otwieraniu Pliku: " 
		<< std::endl;exit(1);
      }
    else
      {
	for(unsigned int i = 0;i < _IloscDanych ; ++i)
	  {
	    Plik_Wart >> Temp;
	    if(Plik_Wart.eof())
	      {
		std::cout << "Napotkany EOF przed wczytaniem wszytskich danych"
			  << std::endl;
	      }
	    _Wartosci[i] = Temp;
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
void StrukturyBenchmark:: _Generator()const
{
  fstream PlikWy;
  srand(time (NULL));

  PlikWy.open("Dane.dat",ios::out);
  if(PlikWy.good())
    {
      for(unsigned int i = 0 ; i < _IloscDanych; ++i)
	PlikWy << rand() % 100 << endl;
    }
  else
    {
      cerr << "Blad utworzenia pliku!" << endl; exit(1);
    }
  PlikWy.close();
}
//*******************************************************************************
