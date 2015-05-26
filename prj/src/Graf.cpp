#include "Graf.hh"
using namespace std;

//*****************************************************************
Graf::Graf(const unsigned int k):
  _V(k),_E(0)
{
  _EMacierz = new unsigned int *[_V];
  for(unsigned int i = 0; i <_V; ++i)
    {
      _EMacierz[i] = new unsigned int [_V];
      for(unsigned int j = 0; j<_V; ++j)
	_EMacierz[i][j] = 0;
    }
  _VMacierz = new unsigned int[_V];
  for(unsigned int i = 0; i <_V; ++i)
    {
      _VMacierz[i] = i;
    }
}
//*****************************************************************
Graf::~Graf()
{
  for(unsigned int i = 0; i<_V; ++i)
    delete [] _EMacierz[i];
  delete [] _EMacierz;
  delete [] _VMacierz;
}
//******************************************************************
void Graf::_DodajKrawedz(const unsigned int i,const unsigned int j)
{
  if(!(i <= _V && j <= _V)) throw"Brak elementu";
  _EMacierz[i][j] = 1;
}
//******************************************************************
void Graf::_UsunKrawedz(const unsigned int i,const unsigned int j)
{
 if(!(i <= _V && j <= _V)) throw"Brak elementu";
  _EMacierz[i][j] = 0;
}
//******************************************************************
bool Graf::_CzyKrawedz(const unsigned int i,const unsigned int j)
{
  if(_EMacierz[i][j])
    return true;
  else
    return false;
}
//******************************************************************
void Graf::BFS(const int W)
{
  Kolejka<int> K;
  bool *Odwiedzone = new bool[_V];
  for(unsigned int i  = 0; i < _V; ++i)
    Odwiedzone[i] = false;
  K._Push(W,K._Rozmiar());
  Odwiedzone[W] = true;
  cout << W << " : " << endl; 
  while(!K.CzyPusta())
    {
      int v = K._Pop();
      cout << v << " " ;
      for(unsigned int j = 0; j < _V; ++j)
	if(_CzyKrawedz(v,j) && !Odwiedzone[j])
	  {
	    K._Push(j,K._Rozmiar());
	    Odwiedzone[j] = true;
	  }
     
    }
  delete [] Odwiedzone;
}
void Graf::DFS(const int x,const int Wymagany)
{
  StosTab<int> S;
  bool *Odwiedzony =new bool[_V];
  for(int i = 0; i < _V; ++i)
    Odwiedzony[i] = false;
  S._Push(x);
  Odwiedzony[x] = true;
  if(x == Wymagany) return;
  cout << x << " : " << endl;
  while(!S.CzyPusty())
    {
      int k = S._Pop();
      if(k == Wymagany) break;
      cout << k << " ";
      for(int i = _V; i >0; --i)
	if(_CzyKrawedz(k,i) && !Odwiedzony[i])
	  {
	    S._Push(i);
	    Odwiedzony[i] = true;
	  }
    }
  delete [] Odwiedzony;
}
