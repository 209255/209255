#include "Graf.hh"
using namespace std;

//*****************************************************************
Graf::Graf(const unsigned int k):
  _V(k)
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
StosTab<int> Graf::DFS()
{
  VertexStatus * S = new VertexStatus[_V];
  StosTab<int> O;
  for(unsigned int i = 0; i <_V; ++i)
    S[i] = Bialy;

  UruchomDFS(0,S,O);
  delete [] S;
  return O;
}
//******************************************************************
void Graf::UruchomDFS(const unsigned int i,VertexStatus S[]
		      ,StosTab<int> &O)
{
  S[i] = Szary;
  for(unsigned int j = 0; j<_V; ++j)
    if(_CzyKrawedz(i,j) && S[j] == Bialy)
      UruchomDFS(j,S,O);
  S[i] = Bialy;
  O._Push(i);
}
//******************************************************************
void Graf::_ZnajdzDroge(const unsigned int k)
{
  StosTab<int> O = DFS();
  Lista<int> Sciezka;
  bool CzyZnalezniono = false;

  for(unsigned int i = 0; i <_V; ++i)
    ;    
}   
//******************************************************************
