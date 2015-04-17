#include"TablicaAso.hh"

using namespace std;


//************************************************************************************************
/*!
 *\file 
 *\brief Definicje Metod klasy TablicaAso
 */
//************************************************************************************************
//***********************************************************************************
int &TablicaAso::operator [](const string &Klucz) 
{
  return _Dodaj(Klucz);
}
//***********************************************************************************
const int TablicaAso::operator ()(const string &Klucz) const
{
  return _Zwroc(Klucz);
}
//***********************************************************************************
void TablicaAso::Usun_wszystkie()
{
  _Wyczysc();
}
//***********************************************************************************