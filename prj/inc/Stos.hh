#ifndef STOS_HH
#define STOS_HH
#include <iostream>
#include "Struktury.hh"

//****************************************************************************************
/*!
 *\file Definicja klasy Stos
 *
 * Plik zawiera definicje klasy Stos wraz z deklaracjami metod,
 * Jest to klasa pochodna od Struktury 
 */
//****************************************************************************************

//****************************************************************************************
/*!
 *\brief Modeluje pojecie Stosu
 *
 * Klasa modeluje pojecie Kolejki,
 * dodajac nowy element na jej koniec i sciagajac 
 * ostatnio dodany Wezel
 */
//****************************************************************************************
template<class Typ>
class Stos : public Struktury<Typ>
{
//****************************************************************************************
/*!
 *\Pole Klasy Stos
 *Pole modelje pojecie wezla,bedacego podstawa dla implementacji struktury danych w rozwinieciu wskaznikowym
 */
//****************************************************************************************

private:

//****************************************************************************************
struct Wezel{
//****************************************************************************************
/*!
 *\brief Pole Wezla
 * Pole bedace wskaznikiem na kolejny element stosu
 */
//****************************************************************************************
	Wezel *_Nast;
//****************************************************************************************
/*!\brief Pole Wezla
 * Pole przechowuje wartoc typu calkowitego
 */
//****************************************************************************************
	Typ _Wartosc;
//****************************************************************************************
};
//****************************************************************************************
/*!
 *\brief Pole klasy Stos
 * Pole jest wskaznikiem na ostatnio dodany Wezel
 */
//****************************************************************************************
	Wezel *Gora;
//****************************************************************************************
/*!
 *\brief Pole klasy Stos
 *Pole przechowuje informacje o ilosci wezlow
 */
//****************************************************************************************
	unsigned int _Ilosc;	
//****************************************************************************************

public:

//****************************************************************************************
/*!
 *\brief Metoda dodajaca nowy Wezel
 *
 * Metoda ma za zadanie dodac nowy wezel na koniec ,
 * umiescic w nim warosc zadana jako argument oraz pokazac 
 * wskaznkiem na ostatni Wezel przed dodaniem nowego Wezla
 *\param[in] k - Wartosc ktora zostanie umieszczona w odpowiednim
 * polu Wezla
 */
//****************************************************************************************
  void _Push(Typ k,unsigned int Pozycja = 0 )
  {
    Wezel *W = new Wezel;
    W ->_Wartosc = k;
    W ->_Nast = Gora;
    Gora = W;
    ++_Ilosc;
  }
//****************************************************************************************
/*!
 *\brief Metda usuwajaca wezel
 *
 * Metoda ma za zadanie zdjac ostatnio dodany element ze stosu danych oraz zwrocic 
 * przechowywana wartosc
 *\return
 * Zwraca ostatnia dodana wartosc 
 */
//****************************************************************************************
  Typ _Pop(unsigned int Pozycja = 0)
  {
    if(_Ilosc == 0) std::cout << "Stos jest Pusty!" << std::endl;
    else
      {
	Wezel *Temp = Gora -> _Nast;
	delete Gora;
	Gora = Temp;
	--_Ilosc;
      }
    return 0;
  }
//****************************************************************************************
/*!
 *\brief Metoda informujaca o obecnej ilosci Wezlow
 *
 * Metoda zwraca informacje o ilosci obecnie 
 * znajdujacych sie elementow na stosie
 *\return - Zwraca ilosc elementow na Stosie 
 */
//****************************************************************************************
  unsigned int _Rozmiar() const {return _Ilosc;}
//****************************************************************************************	
/*!
 *\brief Konstruktor
 *
 * KOnstruktor ma za zadanie ustawic wskaznik na NULL oraz wyzerowac ilosc elmentow 
 * podczas tworzenia obiektu tej klasy
 */
//****************************************************************************************
  Stos(){Gora = NULL; _Ilosc = 0;}
//****************************************************************************************
/*!
 *\brief Destruktor Obiektu
 * Destruktor przy pomocy funkcji pop usuwa wszystkie elemty ze stosu
 */
//****************************************************************************************
  ~Stos()
  {
    while(Gora)
      {
	_Pop();
      }
  }
//****************************************************************************************
/*!
 *\brief Konstruktor Kopiujacy
 */
/*
Stos(const Stos &S)
{
}
*/    
//****************************************************************************************
/*!
 *\brief Metoda wyswietlajaca elementy Stosu
 *
 * Metoda ma za zadanie wyswietlic wszsytkie warotsci
 * znajdujace sie na Stosie
 */
//****************************************************************************************
  void _Pokaz() const
  {
    Wezel *W = Gora;
    if(!Gora) {std::cout << "Stos jest pusty" << std::endl;}
    else
      {
	std::cout << "Wartosc na stosie: " << std::endl ;
	while(W)
	  {
	    std::cout << W->_Wartosc << std::endl;
	    W = W -> _Nast;
	  }
      }
  }
//****************************************************************************************
/*!
 *\brief Metoda zwalniajaca pamiec zajeta przez struktre
 *
 * Metoda ma za zadanie zwolnij pamiec zajeta przez zaladowane do struktury dane,
 * elementy sa usuwany dopoki wskaznik pokazujacy na poczatek  
 * kolejki nie bedzie wskazywal na NULL
 */
//****************************************************************************************
  void _Zwolnij()
  {
    Wezel * Temp = Gora;
    for(unsigned int i= 0; i < _Ilosc; ++i)
      {
	
	Temp = Temp -> _Nast;
	delete Gora;
	Gora = Temp;
      }
    _Ilosc = 0;
  }
//****************************************************************************************
};

#endif
