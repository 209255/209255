#ifndef TABLISTAPOD_HH
#define TABLISTAPOD_HH
#include <cstdlib>
#include <iostream>
#include "Struktury.hh"
//****************************************************************************************
/*!
 *\file Definicja Klasy TabListaPod
 *
 * Plik zawiera definicje klasy Lista,zaimplementowana w sposob tablicowy,realizujacy 
 * realokacje dynamicznej tablicy do 200% poprzedniego rozmiaru.
 * Jest to klasa klasa pochodna od Struktury, naglowke zawiera deklaracje metod 
 */
//****************************************************************************************
template <class Typ>
class TabListaPod : public Struktury<Typ>
{
private:
//****************************************************************************************
/*!
 *\brief Pole klasy ListaTab
 *
 *Pole zawiera wskaznik na typ calkowity, sluzy do alokacji pamieci na dynamiczna tablice
 */
//****************************************************************************************
  Typ * _L;
//****************************************************************************************
/*!
 *\brief Pole Klasy ListaTab
 *
 *Pole przechowuje informacje o ilosci obecnie znajdujacych sie elementow na liscie danych
 */
//****************************************************************************************
  unsigned int _RozmiarL;
//****************************************************************************************
/*!
 *\brief Pole Klasy ListaTab
 *
 *Pole przechowuje informacje o obecnycm rozmiarze tablicy danych
 */
//****************************************************************************************
  unsigned int _RozmiarT;
//****************************************************************************************	
public:
//****************************************************************************************
/*!
 *\brief Konstruktor Kopiujacy
 */
//****************************************************************************************
TabListaPod(const TabListaPod & K)
{
  _L = new Typ[K._RozmiarL];
  for(unsigned int i = 0;i < K._RozmiarL; ++i)
    _L[i] = K._L[i];
}  
//****************************************************************************************
/*!
 *\brief Konstruktor
 *Podczas tworzenia obiektu tej klasy automatycznie alokowana jest tablica o rozmiarze 1
 * oraz ustawienie obecnej liczby elementow listy na 0
 */
//****************************************************************************************
TabListaPod()
{
  _L = new Typ[1];
  _RozmiarL = 0;
  _RozmiarT = 1;
}
//****************************************************************************************
/*!
 *\brief Destruktor obiektu
 */
~TabListaPod(){delete [] _L;}
//****************************************************************************************
/*!
 *\brief Metoda scigajaca element z listy
 *Metoda sciagnac element i w przypadku ,gdy rozmiar tablicy bedzie 
 * dwuktornie wiekszy od ilosci elementow, zostanie zalokowana nowa 
 * tablica o zmniejszonym dwukrotnie rozmiarze
 *
 *\param[in] Pozycja - numer elementu ktory zostanie zwrocony z listy
 *
 *\return
 * Zwraca wartosc elementu z zadanej pozycji
 */
//****************************************************************************************
Typ _Pop(unsigned int Pozycja)
{
  if(_RozmiarL == 0)
    { 
      std::cerr << "Blad! Lista jest pusta!" << std::endl; 
      exit(1);
    }
  else if(Pozycja < 0 || Pozycja > _RozmiarL)
    {
      std::cerr << "Blad! Podano bledny numer pozycji do usuniecia!" << std::endl;
      exit(1);
    }
  else
    {
      Typ Wartosc = _L[Pozycja -1];
      if(_RozmiarT >= 2*_RozmiarL)
	{
	  _XRozszerz(0.5,Pozycja);
	  --_RozmiarL;
	  return Wartosc;
	}
      else
	{
	  _XRozszerz(1,Pozycja);
	  --_RozmiarL;
	  return Wartosc;
	}
    }
  std::cerr << "Blad podczas usuwania elementu z listy!"
	    << std::endl; exit(1);
}
//****************************************************************************************
/*!
 *\brief Dodaje element do listy
 *
 * Metoda ma za zadanie dodac element do listy.
 * W przypaku, gdy skonczy sie miejsce w tablicy,zostaje wowczas
 * alokowana nowa tablica o dwukrotnie wiekszym rozmiarze,
 * w inny przypadku element zostaje dodany w miejscu zadanym
 * przez uzytkownika poprzez argument metody
 *
 *\param[in] k - Wartosc jaka chcemy umiescic na liscie
 *\param[in] Pozycja - Pozycja na ktorej chcemy dodac element
 */
//****************************************************************************************
void _Push(Typ k,unsigned  int Pozycja)
{
  if(_RozmiarL == 0){ _L[0] = k;}
  else if(Pozycja < 0 || Pozycja > _RozmiarL+1)
    {
      std::cerr << "Blad! Podano bledny numer pozycji do dodania!" 
		<< std::endl;
      exit(1);
    }
  else
    { 
      if(_RozmiarT == _RozmiarL)
	{
	  _XRozszerz(2,Pozycja,k);
	}
      else {_XRozszerz(1,Pozycja,k);}
    }
  ++_RozmiarL;
}   
//**************************************************************************************** 
/*!
 *\brief Metoda zwracajaca rozmiar Listy
 *
 * Metoda ma za zadanie zwrocic informacje o aktualnej ilosci
 * elementow na liscie
 *
 *\return
 * Liczba elementow listy
 */
unsigned int _Rozmiar()const {return _RozmiarL;}
//****************************************************************************************
/*!
 *\brief Metoda wypisujaca elemeny listy
 *
 *Metoda ma za zadanie wypisac wszystkie elementy znajdujace sie obecnie 
 * na liscie danych
 */
//****************************************************************************************
void _Pokaz() const
{
  if(_RozmiarL == 0)
    std::cout << "Brak elementow do wyswietlenia" << std::endl;
  else{
    for(unsigned int i = 0; i < _RozmiarL; ++i)
      std::cout << _L[i] << std::endl;
    std::cout << " ";
  }
}
//****************************************************************************************
/*!
 *\brie Metoda zwalniajaca pamiec
 *
 *Metoda ma za zadanie zwolnij pamiec zajmowana przez dane, dopoki ilosc elementow listy nie wynosi
 * 0 wykonywana jest metoda _Pop, aby oproznic stos i zwolnic pamiec
 */
//****************************************************************************************	
void _Zwolnij()
{
  while(_RozmiarL)
      _Pop(1);
}
//****************************************************************************************
void _XRozszerz(const double Ile,unsigned int Pozycja, int k=0)
{
  Typ *Temp = new Typ[_RozmiarT = Ile * _RozmiarT];
  Temp[Pozycja-1] = k;
  for(unsigned int i = 0;i <_RozmiarL; ++i)
    {
      if(i < Pozycja-1){Temp[i] = _L[i];}
      else{Temp[i+1] = _L[i];}
    }
  delete [] _L;
  _L = Temp;
}
//****************************************************************************************	
};
#endif
