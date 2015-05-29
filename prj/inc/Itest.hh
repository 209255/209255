#ifndef ITEST_HH
#define ITEST_HH
//****************************************************************************
/*!
 *\file Zawiera Interfejs testujacy
 *
 * Plik zawiera definicje interfejsu pozwalajacego wykonac benchmark 
 * algorytmu wykonanego dla danej struktury danych
 */
//****************************************************************************

//****************************************************************************
/*!
 *
 *\brief Modeluje pojecie Interfejsu Testujacego
 *
 * Klasa modeluje pojecie abstrakcyjnego interfejsu pozwalajacego wczytac
 * dane do struktury, wykonac pojedyncza operacje testujaca oraz zwolnic zajeta 
 * pamiec
 */
//****************************************************************************

//****************************************************************************
///////////////////////DEFINICJA KLASY////////////////////////////////////////
//****************************************************************************
class Itest
{
public:
//****************************************************************************
/*!
 *\brief Metoda Wywolujaca pojedyncza operacje
 *
 * Metoda ma za zadanie wywolac testowana operacje
 *
 *\param[in] n - wielkosc problemu
 */
//****************************************************************************
  virtual void _Wykonaj(unsigned int n)const  = 0;
//****************************************************************************
/*!
 *\brief Metoda zwalniajaca pamiec
 *
 * Metoda ma za zadanie zwolnic pamiec przeznaczona na dana strukture 
 */
//****************************************************************************
  virtual void _Zwolnij() = 0;
//****************************************************************************
/*!
 *\biref Metoda wczytujaca dane
 *
 * Metoda ma za zadanie wywolac metode umozliwiajaca wczytanie danych do 
 * danej struktury
 *
 *\param[in] n - Wielkosc problemu
 *///****************************************************************************
  virtual void _Zaladuj(const unsigned int n) = 0;
//******************************************************************************
};
//******************************************************************************
/////////////////////////////////KONIEC DEFINICJI///////////////////////////////
//******************************************************************************
#endif
