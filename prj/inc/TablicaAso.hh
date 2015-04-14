#ifndef TablicaAso_HH
#define TablicaAso_HH

#include "TablicaHash.hh"

class TablicaAso:public TablicaHash
{ 

  
public:
  //void _Pokaz()const ;
  int operator ()(const std::string Klucz) const;
  int &operator [](const std::string Klucz); 
  // TablicaAso(){TablicaHash();}
  void Usun_wszystkie();

};


#endif
