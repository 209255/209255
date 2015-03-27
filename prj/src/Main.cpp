#include"ListaTab.hh"
#include"TabListaPod.hh"
#include"Lista.hh"
#include"Stos.hh"
#include"Kolejka.hh"
#include"StosTab.hh"
#include"StrukturyBenchmark.hh"
#define ILOSC_DANYCH 10
using namespace std;
/*!
 *\file
 *\brief funkcja glowna programu
 */
int main(int argc,char *argv[])
{
  ListaTab<double> p;
  TabListaPod<double> H;
  Lista<double> L;
  StrukturyBenchmark<double> K;
  Stos<double> S;
  Lista<double> Z;
  Kolejka<double> k;
  StosTab<double> B;

  if(argc < 2)
     {
       cout << "Nieprawidlowe wywolanie programu!"
	    << "\nWywolanie: ./Struktury [-ilosc powtorzen testow]"
	    << "\nOpcjonalnie : ./Struktury [-ilosc powtorzen testow] [-nazwa pliku z danymi]"
	    << endl;
     }
  else if(argv[2] == NULL)
    {
      cout << "Nie podano pliku z baza danych." << endl;
      cout << "Zostanie on wygenerowany przez program" << endl;
      K._Generator("dat.dat",ILOSC_DANYCH);
      K._Wczytaj("dat.dat",ILOSC_DANYCH);
     
      cout << "\nTestuje Liste" << endl;
      K._Ustaw(Z);
      K._WykonajTest(atoi(argv[1]));

      cout << "\nTestuje Stos" << endl;
      K._Ustaw(S);
      K._WykonajTest(atoi(argv[1]));

      cout << "\nTestuje Kolejke" << endl;
      K._Ustaw(k);
      K._WykonajTest(atoi(argv[1]));
    
      cout << "\ntestuje liste +1" << endl;
      K._Ustaw(p);
      K._WykonajTest(atoi(argv[1]));
     
       
      cout << "\ntestuje liste x2" << endl;
      K._Ustaw(H);
      K._WykonajTest(atoi(argv[1]));
    }
  else
    {
      cout << "\nTestuje Liste" << endl;
      K._Wczytaj(argv[2],ILOSC_DANYCH); 
        K._Ustaw(Z);
      K._WykonajTest(atoi(argv[1]));

      cout << "\nTestuje Stos" << endl;
      K._Ustaw(S);
      K._WykonajTest(atoi(argv[1]));

      cout << "\nTestuje Kolejke" << endl;
      K._Ustaw(k);
      K._WykonajTest(atoi(argv[1]));
      
      cout << "\nTestuje liste +1" << endl;
      K._Ustaw(p);
      K._WykonajTest(atoi(argv[1]));
      
      cout << "\nTestuje liste x2" << endl;
      K._Ustaw(H);
      K._WykonajTest(atoi(argv[1]));
      
      K._Ustaw(B);
      cout << "\nTestuje stos x2" << endl;
      K._WykonajTest(atoi(argv[1]));

    }
  return 0;
}
