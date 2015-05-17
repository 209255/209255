#ifndef DRZEWOBIN_HH
#define DRZEWOBIN_HH
#include "Wezel.hh"

///////////////////////////DEFINICJA KLASY//////////////////////////////////
template<class Typ>
class DrzewoBin:public IDrzewo<Typ>
{
private:
//**************************************************************************
  Wezel<Typ> * _Korzen;
//**************************************************************************
  unsigned int _LiczbaWezlow;
//**************************************************************************
  void DodajGalaz(Wezel<Typ> *&W,const Typ n)
  {
    if(W == NULL)
      {
	Wezel<Typ> * N = new Wezel<Typ>(n);
	N ->_Rodzic = W;
	W = N;
	++_LiczbaWezlow;
      }
    else
      {
	Dodaj(n,W);
      }
  }
//**************************************************************************

public:

//**************************************************************************
  virtual ~ DrzewoBin()
  {
    delete _Korzen;
    _Korzen = NULL;
  }
//**************************************************************************
  DrzewoBin()
  {
    _Korzen = NULL;
    _LiczbaWezlow = 0;
  }
//**************************************************************************
  DrzewoBin(Typ W)
  {
    _Korzen = new Wezel<Typ>(W);
    _LiczbaWezlow = 1;
  } 
//**************************************************************************
  Wezel<Typ> *Wyszukaj (Wezel<Typ> *S, const Typ Wartosc)const 
  {
    if(S ->_Wartosc == Wartosc)
      return S;
    else if( S ->_Wartosc < Wartosc && S ->_Prawy != NULL)
      return Wyszukaj(S ->_Prawy,Wartosc);
    else if( S ->_Wartosc > Wartosc && S ->_Lewy != NULL)
      return Wyszukaj(S ->_Lewy,Wartosc);
    else
      return NULL;
  }
//**************************************************************************  
  void Dodaj(const Typ Wartosc,Wezel<Typ> *S)
  {
    if(_Korzen == NULL)
      {
	_Korzen = new Wezel<Typ>(Wartosc);
	++_LiczbaWezlow;
      }
    else if(Wartosc > S ->_Wartosc)
      {
	DodajGalaz(S ->_Prawy,Wartosc);
      }
    else
      {
        DodajGalaz(S ->_Lewy,Wartosc);
      }
  }
//**************************************************************************	
  void Usun(Wezel<Typ> *S){}
//**************************************************************************
  void PrzejdzDrzewo(Wezel<Typ> *S)
  {
    if(S ->_Lewy != NULL)
      PrzejdzDrzewo(S->_Lewy);
    
    cout << S ->_Wartosc << endl;
    
    if(S->_Prawy != NULL)
      PrzejdzDrzewo(S->_Prawy);
  }
//**************************************************************************
  Wezel<Typ> *_ZwrocKorzen()const {return _Korzen;}
//**************************************************************************
  unsigned int _ZwrocLWezlow()const{return _LiczbaWezlow;}
//**************************************************************************
};
#endif
