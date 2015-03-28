#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include "BenchmarkInterfejs.hh"
#include "Struktury.hh"
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

template<class Typ>
class StrukturyBenchmark: public BenchmarkInterfejs
{

private:

//****************************************************************************************
/*!
 *\brief Pole StrulturyBenchmark
 * Pole zawiera wskaźnik na Struktury, za pomoca niego i metod wirtualnych beda wywolywane 
 * odpowiednie dla danej strktury metody
 */
//****************************************************************************************
  Struktury<Typ> *S;
//****************************************************************************************	
/*!
 *\brief Pole StrkturyBenchmark
 *Pole zawiera wskaznik na typ calkowity, sluzy on do alokowania pamieci dla wczytanych 
 * z pliku danych
 */
//****************************************************************************************
  Typ *W;
//****************************************************************************************
/*!
 *\brief Metoda alokujaca pamiec 
 * 
 * Metoda ma za zadanie zaalokowac odpowiednia ilosc danych w zaleznosci od tego ile 
 * zostalo ich wczytanych 
 *
 *\param[in] n - Ilosc wczytanych danych
 */
//****************************************************************************************
  void _Przydziel(const unsigned int n)
  {
    W = new Typ [n];
    for(unsigned int i = 0; i < n; ++i)
      W[i] = 0;
  }
//****************************************************************************************
/*!
 *\brief Metoda zwalniajaca zaalokowana przez struktury pamiec
 *
 * Metoda ma za zadanie oproznic zaladowane do struktury dane
 *\param[in] n - Ilosc danych ktora zostanie zwolniona
 */ 

//****************************************************************************************
  void _Zwolnij(const unsigned int n) const
  {
    S -> _Zwolnij();
    //  S-> _Pokaz();
  }
//****************************************************************************************
/*!
 *\brief Metoda wykonujaca test dla odpowiedniej struktury
 *
 * Metoda ma za zadanie wykonac zapelnienie struktury danymi o zadanej w argumencie
 * ilosci 
 * \param[in] n - ilosc danych ktora zapelnona struktura 
 */
//****************************************************************************************
  void _Test(const unsigned int n) const 
  {
    for(unsigned int i = 0; i < n; ++i) 
      S -> _Push(W[i],1);
  }
//****************************************************************************************
	
public:

/*!\brief Metoda Wczytujaca dane
 *
 * Metoda ma za zadanie wczytac dane wejciowe o podanej przez 
 * argument nazwie oraz przypisac wskaznik do zaalokwanych w pamieci danych
 *
 *\param[in] PlikIn - nazwa pliku wejsciowego z danymi
 *\param[in] Ilosc - Ilosc danych jaka bedzie wczytywana
 */
//****************************************************************************************
  void _Wczytaj(string PlikIn,const unsigned int Ilosc)
  {
    ifstream Plik_in;
    _Przydziel(Ilosc);
    Plik_in.open(PlikIn.c_str(),ios::in);
    if(!Plik_in)
      {
      std::cerr << "Blad przy otwieraniu Pliku: " << PlikIn << std::endl;
      }
    else
      {
	for(unsigned int i = 0; i< Ilosc; ++i)
	  {
	    Plik_in >> W[i];
	    if(Plik_in.eof())
	      {
		std::cout << "Napotkany EOF przed wczytaniem wszytskich danych" 
			  << std::endl;
	      }
	  }
      }
    Plik_in.close();
  }
//****************************************************************************************
/*!
 *\brief Metoda przypisujaca obiekt danej struktury 
 * 
 * Metoda ma za zadanie pokazywac na testowana obecnie strukture danych, 
 * aby za pomoca wskaznika wywolywac metody z odpowiednich struktur
 *\param[in] K - Adres aktualnie testowanego obiektu danej struktury
 */
//****************************************************************************************
  void _Ustaw(Struktury<Typ> &K){S = &K;}
//****************************************************************************************
/*!
 *\brief Konstruktor
 *
 * Konstruktor sprawia ze wskazniki nowo powstalego obiektu wskazuja na NULL
 */
//****************************************************************************************
  StrukturyBenchmark(){W =NULL;S= NULL;}
//****************************************************************************************
/*!
 *\brief Destruktor
 */
//****************************************************************************************
  virtual ~StrukturyBenchmark(){delete []W;}
//****************************************************************************************


};



#endif
