#ifndef GRAF_HH
#define GRAF_HH
#include<iostream>
#include "Kolejka.hh"
#include "Lista.hh"
#include "StosTab.hh"
#include "Itest.hh"
//***********************************************************************************
/*!
 *\file Plik zawiera definicje klasy Graf
 *
 * Plik zawiera definije klasy Graf wraz z deklaracjami jej metod
 */
//***********************************************************************************

//***********************************************************************************
/*!
 *\brief Modeluje pojecie grafu
 *
 * Klasa modeluje pojecie Grafu, przedstawionego jako Macierz sasiedztw, ktora
 * przechowuje informacje na temat polaczen miedzy wierzcholkami
 */
//***********************************************************************************

//***********************************************************************************
//////////////////////////////DEFINICJA KLASY////////////////////////////////////////
//***********************************************************************************
template <class Typ>
class Graf:public Itest
{
private:
//***********************************************************************************
/*!
 *\brief Pole Klasy Graf
 *
 * Pole zawiera informacje o ilosci wierzcholkow
 */
//***********************************************************************************
  unsigned int _V;
//***********************************************************************************
/*!
 *\brief Pole klasy Graf
 *
 * Pole zawiera informacje o ilosci krawedzi
 */
//***********************************************************************************
  unsigned int _E;
//***********************************************************************************
/*!
 *\brief Pole klasy Graf
 *
 * Pole zawiera informace o polaczeniach miedzy wierzcholkami w grafie
 */
//***********************************************************************************
  int ** _EMacierz;
//***********************************************************************************
/*!
 *\brief Pole klasy Graf
 *
 * Pole przechowuje informacje zapisana w danym wierzcholku
 */
//***********************************************************************************
  Typ * _VMacierz;
//***********************************************************************************
  
  
public:

//***********************************************************************************
/*!
 *\brief Metoda wywolujaca testowany algorytm
 *
 * Metoda ma za zdanie wywolac zaimplementowany dla tej struktury danych algorytm
 *
 *\param[in] n - Wielkosc problemu
 */
//***********************************************************************************
  void _Wykonaj(unsigned int n)const ;
//***********************************************************************************
/*!
 *\brief Metoda zwalniajaca pamiec
 *
 * Metoda ma za zadanie zwolnic pamiec, wykorzystana przez graf
 *\param[in] n - Wielkosc problemu
 */
//***********************************************************************************
  void _Zwolnij();
//***********************************************************************************
/*!
 *\brief Metoda ladujaca dane
 *
 * Metoda ma za zadanie wypelnic macierz sasiedztw informacjami o typie polaczen
 * miedzy wierzcholkami
 */
//***********************************************************************************
  void _Zaladuj(unsigned int n);
//***********************************************************************************
/*!
 *\brief Konstruktor obiektu
 *
 * Konstruktor ma za zadanie zaalokowac pamiec potrzebna dla macerzy sasiedztw 
 * i wstepnie wypelnic ja wartosciami false
 *
 *\param[in] n - wielkosc tworzenego grafu
 */
//***********************************************************************************
  Graf(unsigned int n);
//***********************************************************************************
/*!
 *\brief Destruktor obiektu
 *
 * Destruktor ma zazadanie uwolnic pamiec przeznaczona na realzizajcje grafu
 */
//***********************************************************************************
  virtual ~Graf();
//***********************************************************************************
/*!
 *\brief Metoda dodajaca Krawedz
 *
 * Metoda ma za zadanie zmienic status polaczen zadanych poprzez argument 
 * wierzcholkow na polaczony
 *
 *\param[in] i - numer wierzcholka,ktory ma zostac polaczony z drugim argumentem
 *\param[in] j - numer wierzcholka, ktory ma zostac polaczony z pierwszym argumentem
 */
//*********************************************************************************** 
  void _DodajKrawedz(unsigned int i,unsigned int j);
//***********************************************************************************
/*!
 *\brief Metoda usuwajaca polaczenie
 *
 * Metoda ma zadanie usunac polaczenie miedzy wierzcholkami
 *
 *\param[in] i - numer wierzcholka
 *\param[in] j - numer wierzcholka
 */
//***********************************************************************************
  void _UsunKrawedz(const unsigned int i,const unsigned int j);
//***********************************************************************************
/*!
 *\brief Metoda sprawdzajaca status polaczenia
 *
 * Metoda ma za zadanie sprawdzic status polaczenia miedzy wierzchokami zadanymi
 * poprzez argument
 *
 *\param[in] i - numer wierzcholka
 *\param[in] j - numer wierzcholka
 */
//***********************************************************************************
  bool _CzyKrawedz(const unsigned int i,const unsigned int j)const;
//***********************************************************************************
/*!
 *\brief Algorytm BFS
 *
 * Implemetacja algorytmu przechodzenia grafu wszerz, polegajacego na 
 * przechodzeniu grafu od zadanego wierzcholka i odwiedzeniu wszystkich 
 * dostepnych z niego wierzcholkow.Rezultatem jest drzewo przeszukiwania 
 * wszerz o korzeniu rownemu wierzcholkowi od ktorego rozpoczely sie poszukiwania
 *
 *\param[in] i - Poczatkowy wierzcholek
 *\param[in] Szukany - Wierzcholek koncowy
 */
//***********************************************************************************
  void BFS(const int i,const int Szukany)const;
//***********************************************************************************
/*!
 *\brief Algorytm BFS
 *
 * Implementacja przechodzenia grafu w glab, polegajaca na 
 * badaniu wszystkich krawedzi wychodzacych z podanego wierzcholka.
 * Po zbadaniu wszytskich krawedzi wychodzacych z danego 
 * wierzcholka algorytm powraca do wierzcholka z ktorego
 * dany wierzcholek zostal odwiedzony
 *
 *\param[in] i - Wierzcholek od ktorego zaczyna sie przechodzenie
 *\param[in] Szukany - Wierzcholek na ktorym zakonczone zostaje przechodzenie grafu
 */
//***********************************************************************************
  void DFS(const int x,const int Wymagany)const;
//***********************************************************************************
/*!
 *\brief Metoda dodajaca wartosc do danego wierzcholka
 *
 * Metoda ma za zadanie dodac wartosc do danego wierzcholka
 *
 *\param[in] indeks - Numer wierzcholka do ktorego ma zostac dodana wartosc
 *\param[in] Wartosc - Wartosc,ktora ma zostac dodana do wierzcholka
 */ 
  void _DodajWartoscWierzcholka(const unsigned int indeks,const Typ Wartosc);
//***********************************************************************************
/*!
 *\brief Metoda zwracajaca wartosc z wierzcholka
 *
 * Metoda ma za zadanie zwrocic wartosc z danego wierzcholka
 *
 *\param[in] indeks - Indeks wierzcholka z ktorego ma zostac odczytana wartosc
 */
//***********************************************************************************
  Typ _ZwrocWartoscWierzcholka(const unsigned int indeks)const;
//***********************************************************************************
/*!
 *\brief Metoda zwracaja ilsoc krawedzi
 *
 * Metoda ma za zadanie zwrocic ilosc krawedzi jaka zostala stworzona 
 * w zamodelowanym grafie
 *
 *\return Ilosc krawedzi grafu
 */
//***********************************************************************************
  unsigned int _IloscKrawedzi()const;
//***********************************************************************************
};
//***********************************************************************************
/////////////////////////////KONIEC DEFINICJI////////////////////////////////////////
//***********************************************************************************
#include "../src/Graf.cpp"
#endif
