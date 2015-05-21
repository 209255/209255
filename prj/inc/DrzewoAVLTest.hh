#ifndef DRZEWOAVLTEST_HH
#define DRZEWOAVLTEST_HH
#include"DrzewoAVL.hh"
#include"Itest.hh"

template<class Typ>
class DrzewoAVLTest:public DrzewoAVL<Typ>,public Itest
{
public:
  void _Wykonaj(const unsigned int n,const std::string NazwaPliku)
  {
    ifstream Plik_Wart;
    Typ Temp;
    Plik_Wart.open(NazwaPliku.c_str(),ios::in);
    
    if(!Plik_Wart )
      {
	std::cerr << "Blad przy otwieraniu Pliku: " 
		<< std::endl;exit(1);
      }
    else
      {
	for(unsigned int i = 0;i < n ; ++i)
	  {
	    Plik_Wart >> Temp;
	    if(Plik_Wart.eof())
	      {
		std::cout << "Napotkany EOF przed wczytaniem wszytskich danych"
			  << std::endl;
	      }
	    Szukaj(Temp);
	  }
      }
  }
  void _Zwolnij()
  {}
  void _Zaladuj(const unsigned int n,const std::string NazwaPliku)
  {
    ifstream Plik_Wart;
    Typ Temp;
    Plik_Wart.open(NazwaPliku.c_str(),ios::in);
    
    if(!Plik_Wart )
      {
	std::cerr << "Blad przy otwieraniu Pliku: " 
		<< std::endl;exit(1);
      }
    else
      {
	for(unsigned int i = 0;i < n ; ++i)
	  {
	    Plik_Wart >> Temp;
	    if(Plik_Wart.eof())
	      {
		std::cout << "Napotkany EOF przed wczytaniem wszytskich danych"
			  << std::endl;
	      }
	    Dodaj(Temp);
	  }
      }
  }
};
#endif
