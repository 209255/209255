#ifndef GRAF_HH
#define GRAF_HH
#include<iostream>
#include "Kolejka.hh"
#include "Lista.hh"
#include "StosTab.hh"

class Graf
{
private:

  unsigned int _V;
  unsigned int _E;
  unsigned int ** _EMacierz;
  unsigned int * _VMacierz;
  
  
public:

  Graf(const unsigned n);
  virtual ~Graf();
  void _DodajKrawedz(const unsigned int i,const unsigned int j);
  void _UsunKrawedz(const unsigned int i,const unsigned int j);
  bool _CzyKrawedz(const unsigned int i,const unsigned int j);
  void BFS(const int i);
  void DFS(const int x,const int Wymagany);
};
#endif
