#ifndef TablicaAso_HH
#define TablicaAso_HH
#include "TablicaHash.hh"
//********************************************************************************
/*!
 *\file Definicja Klasy TablicaAso
 *
 * Plik zawiera definicje klasy TablicaAso wraz z interfejsem, na który składają
 * się przeciążenia operarów indeksowania i metoda czyszcząca stan tablicy.
 * Tablica Asocjacyjna jest zrealizowana na podstawie Tablcy Haszującej.
 */
//********************************************************************************

////////////////////////////////DEFINICJA KLASY///////////////////////////////////
class TablicaAso:public TablicaHash
{ 

public:
//********************************************************************************
  /*!
   *\brief operator Indeksowania(odczyt)
   *
   * Przeciazenie operatora indeksowania pozwala nam w latwy sposob
   * odczytac wartosc pasujaca do zadanego poprzez argument Klucza
   *
   *\param[in] Klucz - Klucz dla ktorego zostanie odczytana wartosc
   *
   *\return
   * Zwraca wartosc pasujaca do danego Klucza
   */
//********************************************************************************
  const int operator ()(const std::string &Klucz) const;
//********************************************************************************
/*!
 *\brief operator indeksowania(zapis)
 *
 * Przciazenei operatora indeksowania pozwala nam w latwy sposob
 * dokonac zapisu wartosci w polu skojarzonym z kluczem podanym poprzez argument.
 * Zapis dokonuje sie poprzez zwrocenie referencji pola pasuajcego do danego klucza
 *
 *\param[in] Klucz - Klucz dla ktorego dodana zostanie wartosc
 *
 *\return
 * Zwraca referencje do pola zkojarzonego z podanym poprzez argument 
 * Kluczem
 */
//********************************************************************************
  int &operator [](const std::string &Klucz); 
//********************************************************************************
/*!
 *\brief Metoda Usuwajaca
 *
 * Metoda ma za zadanie usunac cala bierzaca zawartosc tablicy
 */
//********************************************************************************
  void Zwolnij();
//********************************************************************************

};
////////////////////////////////KONIEC DEFINICJI KLASY///////////////////////////

#endif
