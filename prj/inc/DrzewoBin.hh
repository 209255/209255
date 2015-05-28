#ifndef DRZEWOBIN_HH
#define DRZEWOBIN_HH
#include "Wezel.hh"
#include "IDrzewo.hh"

//**************************************************************************
///////////////////////////DEFINICJA KLASY//////////////////////////////////
//**************************************************************************
template<class Typ>
class DrzewoBin
{
private:
//**************************************************************************
  Wezel<Typ> * _Korzen;
//**************************************************************************
  Wezel<Typ>* Dodaj (const Typ Wartosc,Wezel<Typ> *&S)
  {
    if(S == NULL)
      {
	return new Wezel<Typ>(Wartosc);
      }
    if(Wartosc > S->_Wartosc)
      {
         S->_Prawy = Dodaj(Wartosc,S->_Prawy);
      }
    else if(Wartosc <S->_Wartosc)
      {
         S->_Lewy = Dodaj(Wartosc,S->_Lewy);
      }
    
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
  void PrzejdzDrzewo(const Wezel<Typ> *S)const
  {
    if(S ->_Lewy != NULL)
      PrzejdzDrzewo(S->_Lewy);
    
    cout << S ->_Wartosc << endl;
    
    if(S->_Prawy != NULL)
      PrzejdzDrzewo(S->_Prawy);
  }
//**************************************************************************
 const  Wezel<Typ>* Wyszukaj (const Wezel<Typ> *S, const Typ Wartosc)const
  {
    if(S==NULL)
      return NULL;
    if(Wartosc > S->_Wartosc)
      return Wyszukaj(S->_Prawy,Wartosc);
    else if(Wartosc < S->_Wartosc)
      return Wyszukaj(S->_Lewy,Wartosc);
    else
      return S;
  }
//**************************************************************************
 void Usun(Wezel<Typ> *&S)
  {
    if(S != NULL)
      {
	Usun(S->_Lewy);
	Usun(S->_Prawy);
	delete S;
      }
  }
//**************************************************************************

public:

  void _Kasuj()
  {
    Usun(_Korzen);
    _Korzen = NULL;
  }
//**************************************************************************
  void Dodaj(const Typ Wartosc)
  {
    if(_Korzen != NULL)
      (Dodaj(Wartosc,_Korzen));
    else 
      _Korzen = new Wezel<Typ>(Wartosc);
  }
//**************************************************************************
  virtual ~DrzewoBin()
  {
    Usun(_Korzen);
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

Wezel<Typ>* Wyszukaj(const Typ Wartosc)
  {
    Wezel<Typ>*W = _Korzen;
    while((W!=NULL)&&(W->_Wartosc!=Wartosc))
      {
	if(Wartosc <W->_Wartosc)
	  W = W->_Lewy;
	else
	  W = W->_Prawy;
      }
    return W;
  }

//**************************************************************************  
  void Pokaz()
  {
    Wyswietl(_Korzen);
  }
//**************************************************************************
void Wyswietl(Wezel<Typ> *S)
  {
    if(S!=NULL)
      {
	cout<<" " <<  S->_Wartosc << " ";
	Wyswietl(S->_Lewy);
	Wyswietl(S->_Prawy);
      }
  }
//***************************************************************************
};
//****************************************************************************
///////////////////////////////KONIEC DEFINICJI///////////////////////////////
//****************************************************************************

#endif
