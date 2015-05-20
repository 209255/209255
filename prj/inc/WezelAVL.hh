#ifndef WEZELAVL_HH
#define WEZELAVL_HH

template<class Typ>
struct WezelAVL
{
  Typ _Wartosc;
  WezelAVL * _Lewy;
  WezelAVL * _Prawy;
  int _Wysokosc;
  WezelAVL(){ _Wartosc = _Wysokosc = 0; _Lewy = _Prawy = NULL;}
  WezelAVL(Typ k){_Wartosc = k;_Wysokosc = 1;_Lewy = _Prawy = NULL;}
};
#endif
