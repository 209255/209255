#ifndef TABLICAHASH_HH
#define TABLICAHASH_HH
#define ROZMIAR 263167
#include<iostream>
#include<cstring>
#include <sstream>
#include <fstream>
#include "StosTab.hh"

struct Element
  {
    std::string _Klucz;
    int _Wartosc;
  };
 

class TablicaHash
{
private:

  StosTab<Element> *_Tab[ROZMIAR];

protected:
  
  unsigned int _Haszuj(const std::string Klucz) const;
  void _Wyczysc();
  void _Usun(const std::string Klucz);
  Element _Stworz_Rekord(const int ,const std::string);
  TablicaHash();
  ~TablicaHash();
  void _PokazRekord(const std::string Klucz)const; 
  void _Dodaj(const int Data,const std::string Klucz);
  bool _Wczytaj(const std::string PlikIn,const unsigned int Ile);
  TablicaHash(const TablicaHash &k){}
  int _Zwroc(const std::string Klucz)const;
  int& _Dodaj(const std::string Klucz);
public:


  
};
#endif
