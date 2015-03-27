#ifndef KOLEJKA_HH
#define KOLEJKA_HH
#include <iostream>
#include <cstdlib>
#include "Struktury.hh"

//****************************************************************************************
/*!
 *\file Definicja klasy Kolejka
 *
 * Plik zawiera definicje klasy Kolejka,
 * Jest to klasa pochodna od Struktury 
 */
//****************************************************************************************

//****************************************************************************************
/*!
 *\brief Modeluje pojecie Kolejki
 *
 * Klasa modeluje pojecie kolejki,
 * dodajac nowy element na jej koniec i sciagajac 
 * pierwszy doddany element
 */
//****************************************************************************************
template < class Typ>
class Kolejka : public Struktury<Typ>
{
private:
//****************************************************************************************
/*!
 *\Pole Klasy Kolejka
 *Pole modelje pojecie wezla,bedacego podstawa dla implementacji struktury danych w rozwinieciu wskaznikowym
 */
//****************************************************************************************
struct Wezel{
//****************************************************************************************
/*!
 *\brief Pole Wezla
 * Pole bedace wskaznikiem na kolejny element Kolejki
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
 *\brief Pole klasy Kolejka
 *
 * Pole jest wskaznikiem na pierwszy element kolejki
 */
//****************************************************************************************
  Wezel *_Pierwszy;
//****************************************************************************************
/*!
 *\brief Pole klasy Kolejka
 *
 * Pole jest wskaznikiem na ostatni element kolejki
 */
//****************************************************************************************
  Wezel *_Ostatni;
//****************************************************************************************
/*!
 *\brief Pole klasy Kolejka
 *
 *Pole przechowuje inrofmracje o ilosci obecnie znajdujacych sie
 * elementow w kolejce
 */
//****************************************************************************************
  unsigned int _Ilosc;
//****************************************************************************************
public:
//****************************************************************************************
/*!
 *\brief Konstruktor
 *
 * Ustawia wskazniki na NULL oraz zeruje ilosc elementow 
 * przy tworzeniu obiektow danej klasy
 */
//****************************************************************************************
  Kolejka(){_Pierwszy = _Ostatni = NULL;_Ilosc = 0;}
//****************************************************************************************
/*!
 * \brief Destruktor
 */
//****************************************************************************************
  ~Kolejka()
  {
    while(_Pierwszy) 
      _Pop();
  }
//****************************************************************************************
/*!
 *\brief Metoda wyswietlajaca elementu Kolejki
 *
 * Metoda ma za zadanie wyswietlic wszsytkie warotsci
 * znajdujace sie w kolejce
 */
//****************************************************************************************
  void _Pokaz() const
  {
    Wezel *Temp = _Pierwszy;
    if(_Ilosc == 0){ std::cout << "Kolejka pusta!" << std::endl;}
    else
      {
	std::cout << "Wartosci w kolejce: " << std::endl;
	while(Temp)
	  {
	    std::cout << Temp -> _Wartosc << std::endl;
	    Temp = Temp -> _Nast;
	  }
      }
  }
//****************************************************************************************
/*!
 *\brief Metoda dodajaca nowy Wezel
 *
 * Metoda ma za zadanie dodac nowy wezel na koniec kolejki,
 * umiescic w nim warosc zadana jako argument oraz pokazac 
 * wskaznkiem na ostatni Wezel przed dodaniem nowego Wezla
 *\param[in] k - Wartosc ktora zostanie umieszczona w odpowiednim
 * polu Wezla
 */
//****************************************************************************************
  void _Push(Typ k,unsigned int Pozycja = 0)
  {
    Wezel *Temp = new Wezel;
    if(_Ilosc)
      {
	_Ostatni ->_Nast = Temp;
	Temp-> _Wartosc = k;
	Temp -> _Nast = NULL;
	_Ostatni = Temp;
      }
    else
      {
	_Pierwszy = _Ostatni = Temp;
	Temp -> _Wartosc = k;
	Temp -> _Nast = NULL;
      }
    ++_Ilosc;
  }
//****************************************************************************************
/*!
 *\brief Metda usuwajaca wezel
 *
 *Metoda ma za zadanie usunac pierwszy dodany element z kolejki
 * oraz ustawic wskaznik przed ostatniego elementu na NULL
 */
//****************************************************************************************
  Typ _Pop(unsigned int Pozycja = 0)
  {
    if(_Ilosc == 0) { std::cout << "Kolejka pusta!" << std::endl;exit(1);}
    else
      {
	Wezel *Temp = _Pierwszy;
	_Pierwszy = _Pierwszy ->_Nast;
	delete Temp;
	--_Ilosc;
      }
    return 0;
}
//****************************************************************************************
/*!
 *\brief Metoda informujaca o obecnej ilosci Wezlow
 *
 * Metoda zwraca informacje o ilosci obecnie 
 * znajdujacych sie elementow w kolejce
 *\return - Zwraca ilosc elementow w kolejce 
 */
//****************************************************************************************
  unsigned int _Rozmiar() const{return _Ilosc;}
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
    Wezel * Temp = _Pierwszy;
    for(unsigned int i= 1; i < _Ilosc-1; ++i)
      {
	Temp = Temp -> _Nast;
	delete _Pierwszy;
	_Pierwszy = Temp;
      }
    _Ilosc = 0;
  }
//****************************************************************************************	
};


#endif
