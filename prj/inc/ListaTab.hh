#ifndef LISTATAB_HH
#define LISTATAB_HH
#include <cstdlib>
#include <iostream>
#include "Struktury.hh"
//****************************************************************************************
/*!
 *\file Definicja Klasy ListaTab
 *
 * Plik zawiera definicje klasy Lista,zaimplementowana w sposob tablicowy,realizujacy 
 * realokacje dynamicznej tablicy każdorazowo o 1 w momencie dodawania elementu od niej.
 * Jest to klasa klasa pochodna od Struktury, naglowke zawiera deklaracje metod 
 */
//****************************************************************************************


template <class Typ>
class ListaTab : public Struktury<Typ>
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
 *\brief Konstruktor
 *Podczas tworzenia obiektu tej klasy automatycznie alokowana jest tablica o rozmiarze 1
 * oraz ustawienie obecnej liczby elementow listy na 0
 */
//****************************************************************************************
  ListaTab()
  {
    _L = new Typ[1];
    _RozmiarL = 0;
    _RozmiarT = 1;
  }
//****************************************************************************************
/*!
 *\brief Konstruktor Kopiujacy
 */
//****************************************************************************************
  ListaTab(const ListaTab & K)
  {
    _L = new Typ[K._RozmiarL];
    for(unsigned int i = 0;i < K._RozmiarL; ++i)
      _L[i] = K._L[i];
  }  
//****************************************************************************************
/*!
 *\brief Destruktor obiektu
 */
  ~ListaTab(){delete [] _L;};	
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
    }
  }
//****************************************************************************************
/*!
 *\brief Metoda sciagajaca element z listy
 *
 * Metoda ma za zadanie sciagnac wybrany przez uzytkownika element listy oraz 
 * kazdorazowa zmniejszyc tablice z danymi o 1 oraz przekopiowac pozostale elementy listy
 *
 *\param[in] Pozycja - numer elementy kotry zostanie usuniety z listy i zostanie zwrocona jego 
 * wartosc
 *
 *\return
 * Zwraca wybrany przez uzytkownika element
 */
//****************************************************************************************
  Typ _Pop(unsigned int Pozycja)
  {
    if(_RozmiarL == 0)
      { 
	std::cerr << "Blad! Lista jest pusta!" 
		  << std::endl; exit(1);
      }
    else if(Pozycja < 0 || Pozycja > _RozmiarL)
      {
	std::cerr << "Blad! Podano bledny numer pozycji do usuniecia!"
		  << std::endl; exit(1);
      }
    else
      {
	Typ Wartosc = _L[_RozmiarL-1];
	Typ *Temp = new Typ[ _RozmiarT = --_RozmiarL];
	for(unsigned int i = 0; i < _RozmiarL; ++i)
	  {
	    if(i < Pozycja-1){Temp[i] = _L[i];}
	    else{Temp[i] = _L[i+1];}
	  }
	delete [] _L;
	_L = Temp;
	return Wartosc;
      }
    std::cerr << "Blad usunienia elementu z listy! "
	      << std::endl; exit(1);
  }
//****************************************************************************************
/*!
 *\brief Metoda dodajaca elemet do tablicy
 *
 * Metoda ma za zadanie dodac nowy element w wybranym przez uzytkownika miejscu oraz zwiekszyc 
 * kazdorazowa tablice danych o 1 i przepisac pozostale elementy do nowej
 *
 *\param[in] k - wartosc jaka chcemy dodac do listy
 *\param[in] Pozycja - Pozycja na ktorej chcemy dodac wartosc
 */
//****************************************************************************************
  void _Push(Typ k,unsigned  int Pozycja)
  {
    if(_RozmiarL == 0){ _L[0] = k; ++_RozmiarL; }
    else if(Pozycja < 0 || Pozycja > _RozmiarL+1)
      {
	std::cerr << "Blad! Podano bledny numer pozycji do dodania!" 
		  << std::endl; exit(1);
      }
    else 
      {
	Typ *Temp = new Typ[_RozmiarT = ++_RozmiarL];
	Temp[Pozycja-1] = k;
	for(unsigned int i = 0; i < _RozmiarL-1; ++i)
	  {
	    if(i < Pozycja-1){Temp[i] = _L[i];}
	    else{Temp[i+1] = _L[i];}
	  }
	delete [] _L;
	_L = Temp;
      }
  }
//****************************************************************************************  
/*!
 *\brief Metoda zwracajaca rozmiar listy
 * 
 * Metoda zwraca informacje o obecnej ilosci danych w strukturze 
 *
 *\return 
 * Zwraca ilosc elementow listy
 */
  unsigned int _Rozmiar()const {return _RozmiarL;}
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
      _Pop(_RozmiarL);
    //Usuwanie z konca 
  }
//****************************************************************************************
    

};
#endif
