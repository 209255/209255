#ifndef DRZEWOBINTEST_HH
#define DRZEWOBINTEST_HH
#include"DrzewoBin.hh"
#include"Itest.hh"

template<class Typ>
class DrzewoBinTest:public DrzewoBin<Typ>,public Itest
{
//**************************************************************************
  Typ *_Wartosci;
//**************************************************************************

public:
//**************************************************************************
  void Przydziel(const unsigned int n)
  {
    _Wartosci = new Typ[n];
    for(unsigned int i = 0; i <n; ++i)
      {
	_Wartosci[i] = 0;
      }
  }
//**************************************************************************
  void _Wykonaj(const unsigned int n,const std::string NazwaPliku)
  {
    for(unsigned int i = 0; i<n; ++i)
      this -> Dodaj(_Wartosci[i]);
  }
//**************************************************************************  
  void _Zwolnij()
  {
    this->_Kasuj();
  }
//**************************************************************************
  void _Zaladuj(const unsigned int n,const std::string NazwaPliku)
  {
    ifstream Plik_Wart;
    Przydziel(n);
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
	    Plik_Wart >> _Wartosci[i];
	    if(Plik_Wart.eof())
	      {
		std::cout << "Napotkany EOF przed wczytaniem wszytskich danych"
			  << std::endl;
	      }
	    //this ->Dodaj(_Wartosci[i]);
	  }
      }
  }
//**************************************************************************
};
#endif
