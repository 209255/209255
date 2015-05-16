#ifndef WEZEL_HH
#define WEZEL_HH
#include <iostream>

template <class Typ>
struct Wezel
{
  Typ _Wartosc;
  Wezel *_Rodzic; 
  Wezel *_Lewy;
  Wezel *_Prawy;
  Wezel()
  {
    _Lewy =_Prawy = _Rodzic =  NULL; 
  }
  Wezel(Typ W)
  {
    _Wartosc = W;
    _Lewy =_Prawy = _Rodzic =  NULL; 
  }
  virtual ~Wezel()
  {
    delete _Rodzic; delete _Lewy; delete _Prawy;
    _Rodzic = _Lewy = _Prawy = NULL;
  }
};


#endif
