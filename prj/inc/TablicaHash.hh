#ifndef TABLICAHASH_HH
#define TABLICAHASH_HH
#define ROZMIAR 1000033
//#define ROZMIAR 1
#include<iostream>
#include<cstring>
#include <sstream>
#include <fstream>
#include "Element.hh"
#include "StosTab.hh"
//********************************************************************************
/*!
 * \file Definicja klasy TablicaHash
 *
 * Plik zawiera definicje klasy Tablicahash, modeluje ona Tablice haszujaca, 
 * bedaca baza i jednym ze sposobow realzacji tablicy asocjacyjnej
 */
//********************************************************************************




//////////////////////////////////DEFINICJA KLASY/////////////////////////////////
class TablicaHash
{
private:
//********************************************************************************
  /*!
   *\brief Pole klasy TablicaHash
   *
   * Pole to jest tablica wskaznikow o rozmiarze bedacym liczba pierwsza. 
   * Wskazniki wskazuja na abstrakcyjny typ danych, zamodelowany na wczesniejszych 
   * zajeciach. Zadeklarowany stos pracuje na typie danych Element, laczacym klucz 
   * z przypisana do niego wartoscia
   */
//********************************************************************************
  StosTab<Element> *_Tab[ROZMIAR];
//********************************************************************************

protected:

//********************************************************************************
  /*!
   *\brief Funkcja Haszujaca
   *
   * Funkcja ta ma za zadanie okreslic indeks na ktorym
   * zostanie dodany nowy Element do stosu.
   * Metoda zlicza sume znakow Klucza i zwraca reszte z dzielenia
   * wyznaczonej sumy przez rozmiar tablicy haszujacej
   *
   *\param[in] Klucz - Klucz dla ktorego zostanie wyznaczony indeks 
   * tablicy
   *
   *\return Indeks tablicy, odpowiedni dla danego klucza
   */
//********************************************************************************
  const unsigned int _Haszuj(const std::string Klucz) const;
//********************************************************************************
  /*!
   *\brief Metoda kasujaca
   *
   * Metoda ma za zadanie usunac cala aktualna zawartosc tablic haszujacej
   */
//********************************************************************************
  void _Wyczysc();
//********************************************************************************
 /*!
  *\brief Metoda Usuwajaca
  *
  * Metoda ma za zadanie usunac element zdeterminowany przez podany poprzez argument
  * Klucz
  * \param[in] Klucz - Klucz dla ktorego zostanie usuniety pasuajcy Element
  */
//********************************************************************************
  void _Usun(const std::string Klucz);
//********************************************************************************
  /*!
   *\brief  Metoda Tworzaca element
   *
   * Metoda ma za zadanie stworzyc Element
   *
   *\param[in] W - Wartosc skladajaca sie na Element
   *\param[in] K - Klucz skladajacy sie na dany Element
   *
   *\return
   * Zwraca Scalny Element
   */
//********************************************************************************
  Element _Stworz_Rekord(const int W,const std::string K);
//********************************************************************************
 /*!
  *\brief Konstruktor
  *
  * Konstruktor ma za zadanie przypisac do kazdego wskaznika tablicy NULL
  */ 
//********************************************************************************
  TablicaHash();
//********************************************************************************
  /*!
   *\brief Destruktor
   */
//********************************************************************************
  ~TablicaHash();
//********************************************************************************
  /*!
   *\brief Metoda odczytujaca Wartosc
   *
   * Metoda ma za zadanie zwrocic wartosc skojarzona 
   * z podanym poprzez argument Kluczem
   *
   *\param[in] Klucz - klucz dla ktorego zostanie zwrocona
   * odpowiednia wartosc,w przypadku braku pasujacego w bazie klucza
   * zostanie wyswietlony stosowny komunikat
   *
   *\return
   * Zwraca wartosc skojarzona z kluczem
   */
//********************************************************************************
  const int _Zwroc(const std::string &Klucz)const;
//********************************************************************************
/*!
 *\brief Metoda umozliwiajaca dodanie wartosci
 *
 * Metoda ma za zadanie umozliwic przypisanie odpowiedniej wartosci
 * w polu skojarzonym z podanym poprzez argument kluczem, przypisanei odbywa sie 
 * za pomoca zwracania przez ta metode referencji do odpowiedniego pola
 *
 *\param[in] Klucz - Klucz dla ktorego zostanie dodana wartosc
 *
 *\return
 * Zwraca referencje w celu umozliwienia przypisania wartosci w odpowiednie pole
 */
 
//********************************************************************************
  int & _Dodaj(const std::string& Klucz);
//********************************************************************************

};
////////////////////////////////KONIEC DEFINICJI KLASY///////////////////////////
#endif
