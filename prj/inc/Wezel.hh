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
  Wezel(): _Lewy(NULL), _Prawy(NULL),_Rodzic(NULL) {};
  Wezel(Typ W): _Wartosc(W), _Lewy(NULL), _Prawy(NULL),_Rodzic(NULL) {};
};


#endif
