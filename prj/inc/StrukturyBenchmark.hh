#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include "BenchmarkInterfejs.hh"
#include "IDrzewo.hh"

//****************************************************************************************
/*!
 *\file Definicja Klasy StrukturyBenchmark
 *
 *Plik zawiera definicje klasy wraz z deklaracjami jej metod
 */
//****************************************************************************************

//****************************************************************************************
/*!
 * Klasa modeluje pojecie Benchmarku przeznaczonego dla struktur danych 
 * przechowujace dane
 */
//****************************************************************************************

////////////////////////////////DEFINICJA KLASY//////////////////////////////////////////
template<class Typ>
class StrukturyBenchmark: public BenchmarkInterfejs, IObserwowany
{

private:
 
//****************************************************************************************
/*!
 *\brief Pole StrulturyBenchmark
 * Pole zawiera wskaźnik na Struktury, za pomoca niego i metod wirtualnych beda wywolywane 
 * odpowiednie dla danej strktury metody
 */
//****************************************************************************************
  IDrzewo<Typ> *W;
//****************************************************************************************	
/*!
 *\brief Pole StrkturyBenchmark
 *Pole zawiera wskaznik na typ calkowity, sluzy on do alokowania pamieci dla wczytanych 
 * z pliku danych
 */
//****************************************************************************************
  int * _Wartosci;
//****************************************************************************************
/*!
 *\brief Pole StrkturyBenchmark
 *Pole zawiera wskaznik na string, sluzy on do alokowania pamieci dla wczytanych 
 * z pliku danych
 */
//****************************************************************************************
 
//****************************************************************************************
  std::list<IObserwator*> Obserwatorzy;
//****************************************************************************************
  unsigned int _IloscProb;
//****************************************************************************************
  unsigned int _IloscPowt;
//****************************************************************************************
  unsigned int *_TablicaRozmiarow;
//****************************************************************************************
  unsigned int _IloscDanych;
//****************************************************************************************
/*!
 *\brief Metoda wykonujaca test dla odpowiedniej struktury
 *
 * Metoda ma za zadanie wykonac zapelnienie struktury danymi o zadanej w argumencie
 * ilosci 
 * \param[in] n - ilosc danych ktora zapelnona struktura 
 */
//****************************************************************************************
  void _Test(const unsigned int n) const;
//****************************************************************************************
  void _Zaladuj(const unsigned int n) const; 
//**************************************************************************************** 
  //void _Zwolnij(){W -> Zwolnij();}
//****************************************************************************************
  void _PowiadomObserwatorow();
//****************************************************************************************

public:
//****************************************************************************************
  StrukturyBenchmark(unsigned int Proby,unsigned int Powt,
		     unsigned int *Rozmiary);
//****************************************************************************************
  void _WykonajTest();
//****************************************************************************************
  // void _Ustaw(TablicaAso &A){W = &A;}
//****************************************************************************************
/*!\brief Metoda Wczytujaca dane
 *
 * Metoda ma za zadanie wczytac dane wejciowe o podanej przez 
 * argument nazwie oraz przypisac wskaznik do zaalokwanych w pamieci danych
 *
 *\param[in] PlikIn - nazwa pliku wejsciowego z danymi
 *\param[in] Ilosc - Ilosc danych jaka bedzie wczytywana
 */
//****************************************************************************************
  void _Wczytaj(string PlikWart);
//****************************************************************************************
  void _DodajObserwator(IObserwator *O);
//****************************************************************************************
  void _UsunObserwator(IObserwator *O);
//****************************************************************************************
  void _Generator()const;
//****************************************************************************************
};
////////////////////////////////KONIEC DEFINICJI//////////////////////////////////////////
#endif
