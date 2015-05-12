#ifndef CZASOMIERZ_HH
#define CZASOMIERZ_HH
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
////////////////////////////////DEFINICJA KLASY///////////////////////////////////
class Czasomierz
{
private:
//*******************************************************************************
  clock_t _Start;
//*******************************************************************************
  clock_t _Koniec;
//*******************************************************************************
  long double _Aktualny;
//*******************************************************************************
  bool _Status;
//*******************************************************************************

public:

//*******************************************************************************
  Czasomierz();
//*******************************************************************************
  void _RozpocznijPomiar();
//*******************************************************************************
  void _ZakonczPomiar();
//*******************************************************************************
  void  _AktualizujCzas();
//*******************************************************************************
  long double _CzasTrwania()const;
//*******************************************************************************
  void _Reset();
//*******************************************************************************
  bool _StatusPracy()const;
//*******************************************************************************
  double _PojedynczyPomiar()const;
};
///////////////////////////////KONIEC DEFINICJI///////////////////////////////////
#endif