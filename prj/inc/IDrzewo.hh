#ifndef IDRZEWO_HH
#define IDRZEWO_HH
#include "Wezel.hh"
template<class Typ>
class IDrzewo
{
public:
  virtual void Dodaj(const Typ Wartosc,Wezel<Typ> *S) = 0;
  virtual Wezel<Typ> *Wyszukaj(Wezel<Typ>* S,const Typ Wartosc)const  = 0;
  virtual void Usun(Wezel<Typ> *S) = 0;
};
#endif
