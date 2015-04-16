#ifndef ELEMENT_HH
#define ELEMENT_HH

//********************************************************************************
/*!
 *\file Definicja Struktury Element
 *
 * Plik ten zawiera definicje Struktury Element, sluzy on do polaczenia
 * Klucza i wartosci
 */

//********************************************************************************


//********************************************************************************
/*!
 * \brief Element 
 * Element jest struktura laczaca Klucz i wartosc, razem tworzy rekord tablicy 
 * haszujacej
 */
//********************************************************************************

struct Element
  {
//********************************************************************************
    /*!
     *\brief Pole Klucz
     * Pole przechowuje klucz odpowiedniego rekordu
     */
//********************************************************************************
    std::string _Klucz;
//********************************************************************************
    /*!
     *\brief Pole Wartosc
     * Pole przechowuje Wartosc skojarzona z danym kluczem 
     */
//********************************************************************************
    int _Wartosc;
//********************************************************************************
    Element & operator = (const Element &E)
    {
      _Wartosc = E._Wartosc;
      _Klucz = E._Klucz;
      return *this;
    }
//********************************************************************************
  };
#endif
