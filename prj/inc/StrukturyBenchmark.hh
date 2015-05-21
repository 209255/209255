#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include "BenchmarkInterfejs.hh"
#include "Itest.hh"

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
class StrukturyBenchmark: public IObserwowany
{
private:
 //****************************************************************************************
/*!
 *\brief Pole StrukturyBenchmark
 *
 *Pole zawiera liste obserwatorow,ktore obserwuja ten obiekt
 */
//****************************************************************************************
  std::list<IObserwator*> Obserwatorzy;
//****************************************************************************************
/*!
 *\brief Pole StrukturyBenchmark
 *
 * Pole zawiera informacje o ilosci prob jakie zostana wykonane
 */
//****************************************************************************************
  unsigned int _IloscProb;
//****************************************************************************************
/*!
 *\brief Pole StrukturyBenchmark
 *
 * Pole zawiera informacje o ilosci powtorzen jakie maja zosatc wykonane
 * przy tescie 
 */
//****************************************************************************************
  unsigned int _IloscPowt;
//****************************************************************************************
/*!
 *\brief Pole StrukturyBenchmark
 *
 * Pole zawiera wskaznik przechowujacy informcje dla jakiej ilosci danych
 * maja zostac wykonane testy
 */
//****************************************************************************************
  unsigned int *_TablicaRozmiarow;
//****************************************************************************************
/*!
 *\brief Pole StrukturyBenchmark
 *
 * Pole przechowuje informacje o ilosci testyowanych danych
 */
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
/*!
 *\brief Metoda informujaca obserwatorow
 *
 * Metoda ma za zadanie poinformowac wszystkich obserwatorow
 * o zmianach, ktore sa istotne dla nich,
 * jakie zostaly wykonane na obiekcie obserwowanym
 */
//****************************************************************************************
  void _PowiadomObserwatorow()
  {
    std::list<IObserwator *>::iterator it;
    for(it = Obserwatorzy.begin(); it != Obserwatorzy.end(); ++it)
      (*it) -> _Aktualizuj();
  }
//****************************************************************************************

public:

//****************************************************************************************
  StrukturyBenchmark()
  {
    _IloscProb = 0;
    _IloscPowt = 0;
    _TablicaRozmiarow = NULL;
    _IloscDanych = 0;
    std::list<IObserwator *>::iterator it;
    for(it = Obserwatorzy.begin(); it != Obserwatorzy.end(); ++it)
      (*it) = NULL;
  }
//****************************************************************************************
  virtual ~StrukturyBenchmark()
  {
    delete [] _TablicaRozmiarow;
    _TablicaRozmiarow = NULL;

    std::list<IObserwator *>::iterator it;
    for(it = Obserwatorzy.begin(); it != Obserwatorzy.end(); ++it)
      (*it) = NULL;
    }
//****************************************************************************************
/*!
 *\brief Konstruktor obiektu
 *
 */
//****************************************************************************************
  StrukturyBenchmark(unsigned int Proby,unsigned int Powt,
		     unsigned int *Rozmiary)
  {
    _IloscProb = Proby;
    _IloscPowt = Powt;
    _TablicaRozmiarow = new unsigned int[_IloscProb];
    _IloscDanych = Rozmiary[_IloscProb-1];
   
    for(unsigned int i = 0; i < _IloscProb; ++i){
    _TablicaRozmiarow[i] = Rozmiary[i];}

  }
//****************************************************************************************
/*!
 *\brief Metoda inicjalizujaca test
 *
 * Metoda ma za zadanie uruchomic okreslona ilosc
 * razy testowana metode, czas jej wykonania jest zbierany
 * przez klase zewnetrzna
 */
//****************************************************************************************
  void _WykonajTest(Itest *&W,string NazwaPliku)
  {
    for (unsigned int i = 0; i < _IloscProb; ++i)
      {
	for(unsigned int j = 0; j < _IloscPowt; ++j)
	  {
	    W -> _Zaladuj(_TablicaRozmiarow[i],NazwaPliku);
	    this -> _PowiadomObserwatorow();
	    W -> _Wykonaj(_TablicaRozmiarow[i],NazwaPliku);
	    this -> _PowiadomObserwatorow();
	    W -> _Zwolnij();
	  }
      }
  }

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
  void _Wczytaj(string PlikWart)
  {
    ifstream Plik_Wart;
    Typ Temp;
    Plik_Wart.open(PlikWart.c_str(),ios::in);
    
    if(!Plik_Wart )
      {
	std::cerr << "Blad przy otwieraniu Pliku: " 
		<< std::endl;exit(1);
      }
    else
      {
	for(unsigned int i = 0;i < _IloscDanych ; ++i)
	  {
	    Plik_Wart >> Temp;
	    if(Plik_Wart.eof())
	      {
		std::cout << "Napotkany EOF przed wczytaniem wszytskich danych"
			  << std::endl;
	      }
	  
	  }
      }
  }
//****************************************************************************************
/*!
 *\brief Metoda dodajaca obserwator
 *
 * Metoda ma za zadanie dodac nowego  obserwatora do listy
 * obserwatorow danego obiektu
 *
 *\param[in] O - wskaznik na dodawany obserwator
 */
//****************************************************************************************
  void _DodajObserwator(IObserwator *O)
  {
    Obserwatorzy.push_back(O);
  }
//****************************************************************************************
/*!
 *\brief Metoda usuwajaca obserwator
 *
 * Metoda ma za zadanei usunac zadanego poprzez argument obserwatora z listy
 * obserwatorow danego obiektu
 *
 *\param[in] O - wskaznik na obserwator,ktory ma zostac usuniety 
 */
//****************************************************************************************
  void _UsunObserwator(IObserwator *O)
  {
    Obserwatorzy.remove(O);
  }
//****************************************************************************************
/*!
 *\brief Metoda generujaca dane
 *
 * Metoda ma za zadanie wygenerowac pseudolosowe dane 
 * i zapisac je do pliku
 *//*!
 *\brief Metoda generujaca dane
 *
 * Metoda ma za zadanie wygenerowac pseudolosowe dane 
 * i zapisac je do pliku
 */
//****************************************************************************************
  void _Generator()const
  {
    fstream PlikWy;
    srand(time (NULL));
    
    PlikWy.open("Dane.dat",ios::out);
    if(PlikWy.good())
      {
      for(unsigned int i = 0 ; i < _IloscDanych; ++i)
	PlikWy << rand() % 100 << endl;
      }
    else
      {
	cerr << "Blad utworzenia pliku!" << endl; exit(1);
      }
    PlikWy.close();
  }
//****************************************************************************************
};
////////////////////////////////KONIEC DEFINICJI//////////////////////////////////////////
#endif
