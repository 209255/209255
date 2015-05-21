#ifndef DRZEWOBIN_HH
#define DRZEWOBIN_HH
#include "Wezel.hh"
#include "IDrzewo.hh"
///////////////////////////DEFINICJA KLASY//////////////////////////////////
template<class Typ>
class DrzewoBin:public IDrzewo<Typ>
{
private:
//**************************************************************************
  Wezel<Typ> * _Korzen;
//**************************************************************************
  Wezel<Typ>* Dodaj(Typ Wartosc,Wezel<Typ> *&S)
  {
    if(S == NULL)
      S = new Wezel<Typ>(Wartosc);
    else if(Wartosc > S ->_Wartosc)
      Dodaj(Wartosc,S ->_Prawy);
    else 
     Dodaj(Wartosc,S ->_Lewy);
    return S;
  }
//**************************************************************************
  void Pokaz(Wezel<Typ> *W)const
  {
    if(W != NULL)
      {
	cout << " " << W->_Wartosc << " ";
	Pokaz(W ->_Lewy);
	Pokaz(W->_Prawy);
      }
  }
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

public:

//**************************************************************************
  void Dodaj(const Typ Wartosc)
  {
    if(_Korzen == NULL)
      (_Korzen = new Wezel<Typ>(Wartosc));
    else
      (Dodaj(Wartosc,_Korzen));
  }
//**************************************************************************
  virtual ~DrzewoBin()
  {
    delete _Korzen;
    _Korzen = NULL;
  }
//**************************************************************************
  DrzewoBin()
  {
    _Korzen = NULL;
  }
//**************************************************************************
  DrzewoBin(Typ W)
  {
    _Korzen = new Wezel<Typ>(W);
  } 
//**************************************************************************
  bool Wyszukaj (Wezel<Typ> *S, const Typ Wartosc)const 
  {
    if(S ->_Wartosc == Wartosc)
      return true;
    else if( S ->_Wartosc < Wartosc && S ->_Prawy != NULL){
      Wyszukaj(S ->_Prawy,Wartosc); return false;}
    else if( S ->_Wartosc > Wartosc && S ->_Lewy != NULL){
      Wyszukaj(S ->_Lewy,Wartosc); return false;}
    else
      return false;
  }
  bool Wyszukaj(const Typ Wartosc)const
  {
    while(Wyszukaj(_Korzen,Wartosc));
      return true;
  }
//**************************************************************************  
  void Usun(Wezel<Typ> *S){}
//**************************************************************************
  void Pokaz()
  {
    PrzejdzDrzewo(_Korzen);
  }
//**************************************************************************

};
#endif
