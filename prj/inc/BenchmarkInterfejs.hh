#ifndef BENCHMARKINTERFEJS_HH
#define BENCHMARKINTERFEJS_HH

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "Struktury.hh"
using namespace std;
//****************************************************************************************
/*!
 *\file Definicja klasy BenchmarkInterfejs
 *
 * Plik zawiera definicje interfejsu klasy Benchmarkujacej algorytmy,
 * jest to klasa abstrakcyjna bedaca bazowa dla klasy StrukturyBenchmark.
 * Zawierda deklaracje metod czysto wirtualnych oraz metod sluzaych do generowania 
 * i odczytywania pliku z danymi wejsciowymi
 */

//****************************************************************************************
/*!
 *\brief Modeluje pojecie Interfejsu Benchmark'u
 *
 *Klasa bazowa dla implementowania benchmarku dla kolejnych struktur danych
 */
//****************************************************************************************

class BenchmarkInterfejs
{
public:
//****************************************************************************************
/*!
 *\brief Metoda Wykonujaca pojedyncza operacje
 *
 * Metoda ma za zadanie wykonan pojedyncza operacja, ktorej czas jest rejestrowany
 *\param[in] Ilosc - Liczba danych poddana testowi
 */
//****************************************************************************************
  virtual void _Test(const unsigned int Ilosc)const  = 0;
//****************************************************************************************
/*!
 *\brief Metoda wczytujaca dane z pliku
 * Metoda ma za zadanie wczytac dane z pliku wejsciowego
 *\param[in] PlikIn - Nazwa pliku wejsciowego
 *\param[in] n - liczba wczytywanych danych 
 */
//****************************************************************************************
  virtual void _Wczytaj(string PlikIn,const unsigned n) = 0;
//****************************************************************************************
/*!
 *\brief Metoda wykonujaca test odpowiedniej struktury
 *
 * Metoda ma za zadanie wykonac Benchmark dla struktury, dla ustawionej ilosci danych 
 * i okreslona przez argument metody ilosc powtorzen.
 *\param[in] Ilosc_Pow - okresla ile razy ma sie wykonac test
 */
//****************************************************************************************
  void _WykonajTest(const unsigned int Ilosc_Pow) const;
//****************************************************************************************
/*!
 *\bfief Metoda generujaca dane
 * 
 * Metoda ma za zadanie wygenerowac plik z danymi z przedzialu (1-99),
 * jest wywolywana gdy uzytkownik nie poda w argmumencie wywolania programu
 * nazwy pliku wejsciowego z danymi
 *
 *\param[in] PlikOut - Nazwa plik w ktorym zapisywane sa wygenerowane dane 
 *\param[in] n - Ilosc wygenerowanych danych
 */
//****************************************************************************************
  void _Generator(string PlikOut,int n)const;
//****************************************************************************************
/*!
 *\brief Metoda zwalniajaca pamiec
 *
 * Metoda ma zazadanie wykonac operacje zwalaniania pamieci
 *\param[in] n - liczba danych ktora bedzie zwolniona z pamieci
 */
//****************************************************************************************
  virtual void _Zwolnij(const unsigned int n) const  = 0;
//****************************************************************************************
};

#endif
