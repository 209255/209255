#ifndef TREEAVL_HH
#define TREEAVL_HH
#include "WezelAVL.hh"
//*********************************************************************************
////////////////////////////DEFINCIJA KLASY////////////////////////////////////////
//**********************************************************************************
template <class Typ>
class DrzewoAVL
{
private:
//**********************************************************************************
  WezelAVL<Typ> *_Korzen;
//**********************************************************************************
  WezelAVL<Typ> *RotacjaLewa(WezelAVL<Typ> *a);
//**********************************************************************************
  WezelAVL<Typ> *RotacjaPrawa(WezelAVL<Typ> *a);
//**********************************************************************************
  const  WezelAVL<Typ> *Wyszukaj (const WezelAVL<Typ> *S,const Typ Wartosc)const;
//**********************************************************************************
  WezelAVL<Typ> * Rebalans(WezelAVL<Typ> *n);
//**********************************************************************************
  int Wysokosc(WezelAVL<Typ> *n);
//**********************************************************************************
  void Usun(WezelAVL<Typ> *S);
//**********************************************************************************
  void UstawWysokosc(WezelAVL<Typ> *S);
//**********************************************************************************
  int WyznaczWysokosc(WezelAVL<Typ>*S);
//**********************************************************************************
  WezelAVL<Typ>*Dodaj(WezelAVL<Typ> *&S, Typ Wartosc);
//**********************************************************************************
  void PrzejdzDrzewo(WezelAVL<Typ> *S);
//**********************************************************************************
  void InOrder(WezelAVL<Typ>*S);
//**********************************************************************************

public:

//**********************************************************************************
  void Pokaz();
//**********************************************************************************
  void Dodaj(Typ Klucz);
//**********************************************************************************
  DrzewoAVL();
//**********************************************************************************
  ~DrzewoAVL();
//**********************************************************************************
  void Wyszukaj(const int Klucz)const;
//**********************************************************************************
  void _Kasuj();
//**********************************************************************************
};
//**********************************************************************************
/////////////////////////////////KONIEC DEFINICJI///////////////////////////////////
//**********************************************************************************

//**********************************************************************************
template <class Typ>
void DrzewoAVL<Typ>::Dodaj(Typ Wartosc)
{
  if(_Korzen != NULL)
    _Korzen = (Dodaj(_Korzen,Wartosc));
  else
    (_Korzen = new WezelAVL<Typ>(Wartosc)); 
}
//**********************************************************************************
template <class Typ>
int DrzewoAVL<Typ>::WyznaczWysokosc(WezelAVL<Typ>*S)
{
 return (Wysokosc(S->_Prawy) - Wysokosc(S->_Lewy));
}
//**********************************************************************************
template <class Typ>
void DrzewoAVL<Typ>::UstawWysokosc(WezelAVL<Typ> *S)
{
  int l = Wysokosc(S->_Lewy);
  int p = Wysokosc(S->_Prawy);
  S->_Wysokosc = (l>p?l:p)+1;
  
}  
//**********************************************************************************
template <class Typ>
void DrzewoAVL<Typ>::_Kasuj()
{
  Usun(_Korzen);
  _Korzen = NULL;
}
//**********************************************************************************
template <class Typ>
void DrzewoAVL<Typ>::Usun(WezelAVL<Typ> *S)
{
  if(S != NULL)
      {
	Usun(S->_Lewy);
	Usun(S->_Prawy);
	delete S;
      }
}
//**********************************************************************************
template <class Typ>
void DrzewoAVL<Typ>::Wyszukaj(const int Klucz)const 
{
  Wyszukaj(_Korzen,Klucz);
}
//**********************************************************************************
template <class Typ>
DrzewoAVL<Typ>::DrzewoAVL()
{
  _Korzen = NULL; 
}
//**********************************************************************************
template <class Typ>
DrzewoAVL<Typ>::~DrzewoAVL() 
{
  Usun(_Korzen);
}
//**********************************************************************************
template <class Typ>
  WezelAVL<Typ>* DrzewoAVL<Typ>::Rebalans(WezelAVL<Typ> *n)
{

  UstawWysokosc(n);
  if(WyznaczWysokosc(n) == 2)
    {
      if(WyznaczWysokosc(n->_Prawy) < 0){
	n->_Prawy = RotacjaPrawa(n->_Prawy);}
      return RotacjaLewa(n);
    }
  if (WyznaczWysokosc(n) == -2)
    {
      if(WyznaczWysokosc(n->_Lewy) >0){
	n->_Lewy = RotacjaLewa(n->_Lewy);}
      return RotacjaPrawa(n);
    }
  return n;
}
//**********************************************************************************	      
template <class Typ>
WezelAVL<Typ>* DrzewoAVL<Typ>::RotacjaLewa(WezelAVL<Typ> *a) 
{
  WezelAVL<Typ> *Temp = a->_Prawy;
  a->_Prawy = Temp->_Lewy;
  Temp->_Lewy = a;
  UstawWysokosc(a);
  UstawWysokosc(Temp);
  return Temp;
}
//**********************************************************************************
template <class Typ>
WezelAVL<Typ>* DrzewoAVL<Typ>::RotacjaPrawa(WezelAVL<Typ> *a)
{
  WezelAVL<Typ> *Temp = a->_Lewy;
  a->_Lewy = Temp->_Prawy;
  Temp->_Prawy = a;
  UstawWysokosc(a);
  UstawWysokosc(Temp);
  return Temp;
}
//**********************************************************************************
template <class Typ>
int DrzewoAVL<Typ>::Wysokosc(WezelAVL<Typ> *n) 
{
  return n?n->_Wysokosc:0;
}
//**********************************************************************************
template <class Typ>
WezelAVL<Typ>* DrzewoAVL<Typ>::Dodaj(WezelAVL<Typ>*&S, Typ Wartosc) 
{
  if(!S)
    return new WezelAVL<Typ>(Wartosc);
  if(Wartosc <S->_Wartosc)
    S->_Lewy = Dodaj(S->_Lewy,Wartosc);
  else
    S->_Prawy = Dodaj(S->_Prawy,Wartosc);
  return Rebalans(S);
}
//**********************************************************************************
template <class Typ>
const WezelAVL<Typ>*DrzewoAVL<Typ>::Wyszukaj (const WezelAVL<Typ> *S,const Typ Wartosc)const
{
  if(S ->_Wartosc == Wartosc)
    return S;
  else if( S ->_Wartosc < Wartosc && S ->_Prawy != NULL)
    return Wyszukaj(S ->_Prawy,Wartosc); 
  else if( S ->_Wartosc > Wartosc && S ->_Lewy != NULL)
    return Wyszukaj(S ->_Lewy,Wartosc); 
  return NULL;
}
//**********************************************************************************
template <class Typ>
void DrzewoAVL<Typ>::Pokaz()
{
  PrzejdzDrzewo(_Korzen);
}
//**********************************************************************************
template <class Typ>
void DrzewoAVL<Typ>::PrzejdzDrzewo(WezelAVL<Typ> *S)
  {
    if(S!=NULL)
      {
	cout<<" " <<  S->_Wartosc << " ";
	PrzejdzDrzewo(S->_Lewy);
	PrzejdzDrzewo(S->_Prawy);
      }
  }
//**********************************************************************************
template<class Typ>
void DrzewoAVL<Typ>::InOrder(WezelAVL<Typ>*S)
{
  if(S->_Lewy!=NULL)
    InOrder(S->_Lewy);
  cout << S->_Wartosc << endl;

  if(S->_Prawy!=NULL)
    InOrder(S->_Prawy);
}
//**********************************************************************************
#endif
