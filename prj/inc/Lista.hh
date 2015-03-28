#ifndef LISTA_HH
#define LISTA_HH
#include <iostream>
#include "Struktury.hh"

//****************************************************************************************
/*!
 *\file Definicja Klasy Lista
 *
 * Plik zawiera definicje klasy Lista,bedaca klasa pochodna od Struktury, wraz z deklaracjami metod
 */
//****************************************************************************************


template <class Typ>
class Lista : public Struktury<Typ>
{
private:
//****************************************************************************************
/*!
 *\Pole Klasy lista
 *Pole modelje pojecie wezla,bedacego podstawa dla implementacji struktury danych w rozwinieciu wskaznikowym
 */
//****************************************************************************************
struct Wezel{
//****************************************************************************************
/*!
 *\brief Pole Wezla
 * Pole bedace wskaznikiem na kolejny element listy
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
 *\brief Pole klasy Lista
 *Wskaznik na nowo dodany Wezel
 */
//****************************************************************************************
  Wezel *Glowa;
//****************************************************************************************
/*!
 *\brief Pole klasy Lista
 * Pole przechowuje bierzaca ilosc elementow listy 
 */
//****************************************************************************************
  unsigned int _Ilosc;
//****************************************************************************************
/*!
 *\brief Metoda zwalniajaca pamiec zajeta przez struktre
 *
 * Metoda ma za zadanie zwolnij pamiec zajeta przez zaladowane do struktury dane,
 * elementy sa usuwany dopoki wskaznik pokazujacy na poczatek  
 * listy nie bedzie wskazywal na NULL
 */ 
//****************************************************************************************
  void _Zwolnij()
  {
    // cout << "zwalniam" << endl;
    Wezel * Temp = Glowa;
    for(unsigned int i= 1; i < _Ilosc-1; ++i)
      {
	Temp = Temp -> _Nast;
	delete Glowa;
	Glowa = Temp;
      }
    _Ilosc = 0;
}
//****************************************************************************************

public:

//****************************************************************************************
/*!
 *\brief Metoda dodajaca Wezel
 *
 * Metoda ma za zadanie dodac element do listy w zaleznosci od argumentu miejscu 
 * i usatwic wartosc zadana przez argument
 *\param[in] wart - Wartosc jaka zostana dodana do Wezla 
 *\param[in] poz - Pozycja w ktorej zosatnie dodany Wezel
 */
//****************************************************************************************
  void _Push(Typ Wart,unsigned int Poz)
  {
    //Poz = _Ilosc + 1;
    Wezel *Nowy = new Wezel; 
    Wezel *Stary; 
    Wezel *Temp = Glowa; 
    Nowy->_Wartosc = Wart; 
    unsigned int nr = _Rozmiar(); 
    if(Poz>(nr)) Poz = nr+1;
    if(!Glowa){ Glowa = Nowy; }
    else
      { 
	if(Poz <= 1)
	  {
	    Stary = Glowa;
	    Glowa = Nowy; 
	    Glowa->_Nast = Stary; 
	  }
	else
	  { 
	    for(unsigned int i = 1; i < (Poz-1); ++i) { Temp = Temp->_Nast; } 
	    Stary = Temp->_Nast; 
	    Temp->_Nast = Nowy; 
	    Temp->_Nast->_Nast = Stary; 
	  }
      } 
    ++_Ilosc;
}
//****************************************************************************************
/*!
 *\brief Metoda usuwajaca Wezel
 * 
 *Metoda ma za zadanie usunac wezel zgodny z argumentem metody
 *Wezel zosatnie usuniety, a sasiednie elementy zostana polaczaone wskazniekiem
 *
 *\param[in] Pozycja - Numer Wezla ktory zostanie usuniety
 */
//****************************************************************************************
  Typ _Pop(unsigned int Pozycja)
  {
    Wezel* Temp = Glowa; 
    Wezel * Temp2;
    if(Pozycja == 1)
      { 
	Wezel * T = Glowa -> _Nast;
	delete Glowa; 
	Glowa = T;
      }
    
    else 
      {   
	for(unsigned int i = 1; i < (Pozycja-1); ++i){
	  Temp = Temp -> _Nast; }
	if(Temp -> _Nast -> _Nast == NULL)
	  { 
	    delete Temp -> _Nast; 
	    Temp -> _Nast = NULL; 
	  }
	else
	  { 
	    Temp2 = Temp ->_Nast;
	    Temp -> _Nast = Temp2 -> _Nast;
	    delete Temp2;
	  }
      }
    --_Ilosc;
    return 0;
  }    
//****************************************************************************************
/*!
 *\brief Metoda informujaca o ilosci wezlow
 *
 *Metoda zwraca informajce o ilosci aktualnych wezlow listy
 *\return - Ilosc elementow listy
 */
//****************************************************************************************
  unsigned int _Rozmiar() const{return _Ilosc;}
//****************************************************************************************
/*!
 *\brief Konstruktor
 *
 * Konstruktor ustawia wskaznik na NULL i zeruje ilosc wezlow listy
 */
//****************************************************************************************
  Lista(){Glowa = NULL;_Ilosc = 0;}
//****************************************************************************************
/*!
 *\brief Destruktor 
 *Usuwa wskaznik
 */
//****************************************************************************************
  ~Lista(){delete Glowa;}
//****************************************************************************************
/*!
 *\brief Konstruktor Kopiujacy
 */
	//Lista(const Lista &A);
//****************************************************************************************
/*!
 *\brief Metoda wyswietlajaca elementy Listy
 *
 * Metoda ma za zadanie wyswietlic wszsytkie warotsci
 * znajdujace sie na Liscie
 */
//****************************************************************************************
  void _Pokaz() const
  {
    Wezel * Temp = Glowa;
    if(_Ilosc == 0) { std::cout << "Lista pusta!" << std::endl;}
    else
      {
	std::cout << "Wartosc listy: " <<std:: endl;
	while(Temp)
	  {
	    std::cout << Temp -> _Wartosc << std::endl;
	    Temp = Temp -> _Nast;
	  }
      }
  }
//***************************************************************************************   


};
#endif
