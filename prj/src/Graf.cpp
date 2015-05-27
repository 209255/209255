#include "Graf.hh"
using namespace std;

//*****************************************************************
Graf::Graf(unsigned int k):
  _V(k),_E(0)
{
  _EMacierz = new unsigned int *[_V];
  for(unsigned int i = 0; i < _V; ++i)
    {
      _EMacierz[i] = new unsigned int [_V];
      for(unsigned int j = 0; j < _V; ++j)
	_EMacierz[i][j] = 0;
    }
  _VMacierz = new unsigned int[_V];
  for(unsigned int i = 0; i < _V; ++i)
    {
      _VMacierz[i] = i;
    }
}
//*****************************************************************
Graf::~Graf()
{
  for(unsigned int i = 0; i< _V; ++i)
    delete [] _EMacierz[i];
  delete [] _EMacierz;
}
//******************************************************************
void Graf::_DodajKrawedz(unsigned int i, unsigned int j)
{
  //cout<<"i: "<<i <<"j; " << j <<endl;
  if(!(i <= _V && j <= _V)) throw"Brak elementu";
  _EMacierz[i-1][j-1] = 1;
  ++_E;
}
//******************************************************************
void Graf::_UsunKrawedz(const unsigned int i,const unsigned int j)
{
 if(!(i <= _V && j <= _V)) throw"Brak elementu";
  _EMacierz[i][j] = 0;
  --_E;
}
//******************************************************************
bool Graf::_CzyKrawedz(const unsigned int i,const unsigned int j)const
{
  if(_EMacierz[i][j])
    return true;
  else
    return false;
}
//******************************************************************
void Graf::BFS(const int W,const int Szukany)const
{
  Kolejka<int> K;
  bool *Odwiedzone = new bool[_V];
  for(unsigned int i  = 0; i < _V; ++i)
    Odwiedzone[i] = false;
  K._Push(W,K._Rozmiar());
  Odwiedzone[W] = true;
  while(!K.CzyPusta())
    {
      int v = K._Pop();
      if(v == Szukany) break;
      for(unsigned int j = 0; j < _V; ++j)
	if(_CzyKrawedz(v,j) && !Odwiedzone[j])
	  {
	    K._Push(j,K._Rozmiar());
	    Odwiedzone[j] = true;
	  }
     
    }
  delete [] Odwiedzone;
}
//******************************************************************
void Graf::DFS(const int x,const int Wymagany)const
{
  StosTab<int> S;
  bool *Odwiedzony =new bool[_V];
  for(unsigned int i = 0; i < _V; ++i)
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
      for(unsigned int i = _V; i >0; --i)
	if(_CzyKrawedz(k,i) && !Odwiedzony[i])
	  {
	    S._Push(i);
	    Odwiedzony[i] = true;
	  }
    }
  delete [] Odwiedzony;
}
//******************************************************************
void Graf:: _Zaladuj(unsigned int n)
  {
    const unsigned int m = (n/2);
    for(unsigned int i = 1; i < n; ++i)
      {
       	if(i < m)
	  {
	    //cout << "i: " << i << endl;
	    _DodajKrawedz(i,i+1);
	    _DodajKrawedz(i,m+i);
	    _DodajKrawedz(i,m+i+1);
	  }
	if(i > m)
	  _DodajKrawedz(i,i+1);
      }
  }
void Graf::_Wykonaj(unsigned int n)const
{
  const int m = n/2;
  this ->BFS(1,m+1);
}
void Graf::_Zwolnij()
{
  this->Graf::~Graf();
}
