#ifndef GRAF_HH
#define GRAF_HH
#include<iostream>
#include "StosTab.hh"
#include "Lista.hh"

class Graf
{
  unsigned int _V;
  unsigned int _E;
  unsigned int ** _EMacierz;
  unsigned int * _VMacierz;
  enum VertexStatus{Bialy,Szary,Czarny};
  void UruchomDFS(const unsigned int y,VertexStatus [],StosTab<int> &O);
  
public:

  Graf(const unsigned n);
  virtual ~Graf();
  void _DodajKrawedz(const unsigned int i,const unsigned int j);
  void _UsunKrawedz(const unsigned int i,const unsigned int j);
  void _ZnajdzDroge(const unsigned int k);
  bool _CzyKrawedz(const unsigned int i,const unsigned int j);
  StosTab<int> DFS();
};
#endif
