#include"TablicaAso.hh"

using namespace std;
//***********************************************************************************
int &TablicaAso::operator [](const string Klucz) 
{
  return _Dodaj(Klucz);
}
//***********************************************************************************
int TablicaAso::operator ()(const string Klucz) const
{
  return _Zwroc(Klucz);
}
//***********************************************************************************
void TablicaAso::Usun_wszystkie()
{
  _Wyczysc();
}
//***********************************************************************************
