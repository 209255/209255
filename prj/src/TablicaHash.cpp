#include "TablicaHash.hh"

using namespace std;


//************************************************************************************************
/*!
 *\file 
 *\brief Definicje Metod klasy TablicaHash
 */
//************************************************************************************************
//***********************************************************************************
TablicaHash::TablicaHash()
{
  for(int i = 0; i < ROZMIAR; ++i)
    _Tab[i] = NULL;
}
//***********************************************************************************
TablicaHash::~TablicaHash()
{
  for(int i = 0; i < ROZMIAR; ++i) 
    delete _Tab[i];
}
//***********************************************************************************
const unsigned int TablicaHash::_Haszuj(const string Klucz) const 
{
  unsigned int suma = Klucz[0];
  for(unsigned int i = 0; i < Klucz.size(); ++i)
    suma = ((suma << 5)) + Klucz[i];
  return suma % ROZMIAR;
 }
//***********************************************************************************
Element TablicaHash::_Stworz_Rekord(const int Data,const string Klucz)
{
  Element Rekord;
  Rekord._Klucz = Klucz;
  Rekord._Wartosc = Data;
  return Rekord;
}
//***********************************************************************************
void TablicaHash::_Wyczysc()
{
  for (unsigned int i = 0; i <ROZMIAR; ++i)
    {
      while(_Tab[i] -> _Rozmiar())
	_Tab[i] -> _Pop();
    }
  cout << "Usuwanie zakończone sukcesem!" << endl;
}
//***********************************************************************************
int& TablicaHash::_Dodaj(const string &Klucz)
{
  const Element Para = _Stworz_Rekord(0,Klucz);
  const unsigned int Index = _Haszuj(Klucz);
  //cout << "Index: " << Index << endl;
  int i = 0;
  if(!(_Tab[Index]))
    {
      _Tab[Index] = new StosTab<Element>;
      _Tab[Index] -> _Push(Para);
      return _Tab[Index] -> _Adres(0)._Wartosc;
    }
  
  else
    {
      _Tab[Index] -> _Push(Para);
      while(Klucz != (_Tab[Index] -> _Wartosc(i)._Klucz)) i++;
      return _Tab[Index] -> _Adres(i)._Wartosc;
    }
  cerr << "Blad! Nie znalezniono odpowiedniego rekordu dla podanego klucza!"
       << endl; exit(1);
}
//***********************************************************************************
const int TablicaHash::_Zwroc(const string &Klucz) const
{
  
  const unsigned int index = _Haszuj(Klucz);
  if(!_Tab[index]){
      cerr << "Blad!Brak odpowiedniego rekordu!"
	   << endl; exit(1);}
  else
    {
      const unsigned int Rozmiar = _Tab[index] -> _Rozmiar();
      for(unsigned int i = 0; i < Rozmiar; ++i)
	{
	  if(Klucz == (_Tab[index] -> _Wartosc(i))._Klucz) 
	    return _Tab[index] -> _Wartosc(i)._Wartosc;
	  
	}
    }
  cerr << "Blad! Nie znalezniono odpowiedniego rekordu dla podanego klucza!"
       << endl; exit(1);
}
//***********************************************************************************
