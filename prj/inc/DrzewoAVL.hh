#ifndef DRZEWOAVL_HH
#define DRZEWOAVL_HH
#include"Wezel.hh"
#include"IDrzewo.hh"
#include<cstring>

template<class Typ>
class DrzewoAVL: public IDrzewo<Typ>
{
private:

//**************************************************************************
  Wezel<Typ>* _Korzen;
//**************************************************************************
  int Wysokosc(Wezel<Typ> *W)const 
  {
    if(W == NULL)
      return 0;
    int l = Wysokosc(W ->_Lewy);
    int r = Wysokosc(W ->_Prawy);
    if(l > r)
      return l+1;
    else
      return r+1;
  }
//**************************************************************************
  void RotacjaPrawa(Wezel<Typ> *&W)
  {
    Wezel<Typ> *Temp = W ->_Prawy;
    W ->_Prawy = Temp ->_Lewy;
    Temp ->_Lewy = W;
    W = Temp;
  }
//**************************************************************************
  void RotacjaLewa(Wezel<Typ> *&W)
  {
    Wezel<Typ> *Temp = W ->_Lewy;
    W ->_Lewy = Temp ->_Prawy;
    Temp ->_Prawy = W;
    W = Temp;
  }
//**************************************************************************
  void RotacjaRL(Wezel<Typ> *&W)
  {
    RotacjaPrawa(W->_Lewy);
    RotacjaLewa(W);
  }
//**************************************************************************
  void RotacjaLR(Wezel<Typ> *&W)
  {
    RotacjaLewa(W->_Prawy);
    RotacjaPrawa(W);
  }
//**************************************************************************
  Wezel<Typ>* Dodaj(Typ Wartosc,Wezel<Typ> *&S)
  {
    if(S == NULL)
      S = new Wezel<Typ>(Wartosc);
    else if(Wartosc < S->_Wartosc)
      {
	Dodaj(Wartosc,S->_Lewy);
	if((Wysokosc(S->_Lewy) - Wysokosc(S->_Prawy)) == 2)
	  {
	    if(Wartosc < S->_Lewy->_Wartosc)
	      RotacjaLewa(S);
	    else
	      RotacjaRL(S);
	  }
      }
    else
      {
	Dodaj(Wartosc,S->_Prawy);
	if((Wysokosc(S->_Prawy) - Wysokosc(S->_Lewy)) == 2)
	  {
	    if(Wartosc > S->_Prawy->_Wartosc)
	      RotacjaPrawa(S);
	    else
	      RotacjaLR(S);
	  }
      }
    return S;
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
  void Pokaz(Wezel<Typ> *W)const
    {
      if(W !=NULL)
	{
	  cout << " " << W->_Wartosc << " ";
	  Pokaz(W ->_Lewy);
	  Pokaz(W->_Prawy);
	}
    }
//**************************************************************************  

public:

//**************************************************************************
  virtual ~DrzewoAVL()
  {
    delete _Korzen;
    _Korzen = NULL;
  }
//**************************************************************************
  DrzewoAVL()
  {
    _Korzen = NULL;
  }
//**************************************************************************
  DrzewoAVL(const Typ W)
  {
    _Korzen = new Wezel<Typ>(W);
  } 
//**************************************************************************
  bool Wyszukaj (Wezel<Typ> *S, const Typ Wartosc)const 
  {
    if(S ->_Wartosc == Wartosc)
      return true;
    else if( S ->_Wartosc < Wartosc && S ->_Prawy != NULL){
      Wyszukaj(S ->_Prawy,Wartosc);return false;}
    else if( S ->_Wartosc > Wartosc && S ->_Lewy != NULL){
      Wyszukaj(S ->_Lewy,Wartosc);return false;}
    else
      return false;
  }
  bool Wyszukaj(const Typ Wartosc)const
  {
    while(!Wyszukaj(_Korzen,Wartosc));
    return true;
  }
//**************************************************************************  
  void Dodaj(const Typ Wartosc)
  {
    if(_Korzen == NULL)
      _Korzen = new Wezel<Typ>(Wartosc);
    else
      Dodaj(Wartosc,_Korzen);
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
