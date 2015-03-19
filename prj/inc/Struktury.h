#ifndef INTERFEJS_H
#define INTERFEJS_H
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
/*!
 *\file Definicja klasy Struktury 
 *
 * Plik zawiera definicje klasy Struktry, bedząca klasa 
 * abstrakcyjna i bazowa dla pochodnych Struktur danych.
 * Zawiera deklaracje metod czysto wirtualnych
 */

/*!
 *\brief Modeluje pojecie Struktury danych,
 * klasa bazowa dla Stosu,Kolejki i Listy.
 */
class Struktury{
protected:
/*!
 * \brief Modeluje pojecie wezla
 * Struktura przeznaczona do dziedziczenia dla klas pochodnych, opartych o 
 * dzialanie listy
 */	
struct Wezel{
/*!
 *\brief Pole Wezla
 * Pole bedace wskaznikiem na kolejny element listy
 */
	Wezel *_Nast;
/*!\brief Pole Wezla
 * Pole przechowuje wartoc typu calkowitego
 */
	int _Wartosc;
};
public:
/*!
 *\brief Metoda dodajaca kolejny Wezel
 *
 * Metoda ma za zadanie dodac kolejny wezel do naszej struktury 
 * oraz zapisac w nim odpowiednia wartosc.W zaleznosci od implementowanej struktury
 * element bedzie dodawany na poczatku lub na koncu listy.
 *
 *\param[in] k - wartosc typu calkowitnego, ktora bedzie umieszona w wezle
 */
  virtual void Push(int k) = 0;
/*!
 *\brief Metoda usuwajaca Wezel
 *
 * Metoda ma za zadanie usunac wezel i w zaleznosci od implementowanej struktury
 * bedzie to usuwany element z poczatku lub konca listy Wezlow
 */
  virtual void Pop() = 0;
/*!
 *\brief Metoda zwracajaca rozmiar Struktury
 *
 * Metoda ma zadanie zwrocic bierzaca liczbe elementow nalezacych do danej struktury
 *\return - Bierzaca liczba elementow Struktury danych
 */ 
  virtual unsigned int Rozmiar() = 0;
/*!
 *\brief Metoda wyswietlajaca dane 
 *
 * Metoda ma za zadanie wyswietlic wszytskie dane nalezace do struktury 
 */
  virtual void Pokaz() = 0;

  };
#endif