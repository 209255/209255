#ifndef DRZEWOBIN_HH
#define DRZEWOBIN_HH
#include "Wezel.hh"
template<class Typ>
class DrzewoBin:public IDrzewo<Typ>
{
private:

  Wezel * _Korzen;
  unsigned int _LiczbaWezlow;

  void DodajGalaz(Wezel *W,const Typ N)
  {
    if(W -> != NULL)
      {
	Dodaj(Wartosc,W);
	++_LiczbaWezlow;
      }
    else
      {
	Wezel * N = new Wezel(Wartosc);
	N ->_Rodzic = W;
	W = N;
	++_LiczbaWezlow;
      }
  }
public:

  DrzewoBin(): _Korzen(NULL), _LiczbaWezlow(0){};
  DrzewoBin(Typ W): _Korzen->_Wartosc(W),_LiczbaWezlow(1){}; 
  Wezel *Wyszukaj (Wezel *S, const Typ Wartosc)const 
  {
    if(S ->_Wartosc == Wartosc)
      return S;
    else if( S ->_Wartosc < Wartosc && S ->_Prawy != NULL)
      return Wyszuka(S ->_Prawy,Wartosc);
    else if( S ->_Wartosc > Wartosc && S ->_Lewy != NULL)
      return Wyszukaj(S ->_Lewy,Wartosc);
    else
      return NULL;
  }
  

    
  void Dodaj(const Typ Wartosc,Wezel *S)
  {
    if(_Korzen == NULL)
      {
	_Korzen = new Wezel(Wartosc);
	++_LiczbaWezlow;
      }
    else if(Wartosc < S ->_Wartosc)
      {
	DodajGalaz(S ->_Lewy,Wartosc);
      }
    else
      {
        DodajGalaz(S ->_Prawy,Wartosc);
      }
  }
	
  void Usun(Wezel *S){}

};
#endif
