#ifndef IDRZEWO_HH
#define IDRZEWO_HH
#include "Wezel.hh"
template<class Typ>
class IDrzewo
{
public:
  virtual void Dodaj(const Typ Wartosc,Wezel *S) = 0;
  virtual Wezel *Wyszukaj(Wezel* S,const Typ Wartosc)const  = 0;
  virtual void Usun(Wezel *S) = 0;
};
#endif
