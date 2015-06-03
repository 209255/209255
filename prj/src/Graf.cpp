//*****************************************************************
/*!
 *\file Zawiera definicje metod klasy Graf
 */
//*****************************************************************

//*****************************************************************
template <class Typ>
Graf<Typ>::Graf(unsigned int k):
  _V(k),_E(0)
{
  _EMacierz = new int *[_V];
  for(unsigned int i = 0; i < _V; ++i)
    {
      _EMacierz[i] = new int [_V];
      for(unsigned int j = 0; j < _V; ++j)
	_EMacierz[i][j] = 0;
    }
  
  _VMacierz = new Typ[_V];
  for(unsigned int i = 0; i < _V; ++i)
    _VMacierz[i] = 0;
}
//*****************************************************************
template <class Typ>
Graf<Typ>::~Graf()
{
  for(unsigned int i = 0; i < _V; ++i)
    delete []_EMacierz[i];
  delete [] _EMacierz;
  
}
//******************************************************************
template <class Typ>
void Graf<Typ>::_DodajKrawedz(const unsigned int i, const unsigned int j)
{
  // cout <<"i: " << i << "j: " << j <<endl;
  if(!(i <= _V && j <= _V)) throw"Brak elementu";
  _EMacierz[j-1][i-1] = _EMacierz[i-1][j-1] +=1;
  ++_E;
}
//******************************************************************
template <class Typ>
void Graf<Typ>::_UsunKrawedz(const unsigned int i,const unsigned int j)
{
 if(!(i <= _V && j <= _V)) throw"Brak elementu";
  _EMacierz[i-1][j-1] = 0;
  --_E;
}
//******************************************************************
template <class Typ>
bool Graf<Typ>::_CzyKrawedz(const unsigned int i,const unsigned int j)const
{
  return(_EMacierz[i-1][j-1] == true);
}
//******************************************************************
template <class Typ>
void Graf<Typ>::BFS(const int W,const int Szukany)const
{
  //cout << Szukany<< endl;
  Kolejka<int> K;
  bool *Odwiedzone = new bool[_V+1];
  for(unsigned int i  = 1; i <= _V; ++i)
    Odwiedzone[i] = false;
  K._Push(W,K._Rozmiar());
  Odwiedzone[W] = true;
  //cout << W << " : " << endl;
  if(W == Szukany) return;
  while(!K.CzyPusta())
    {
      int v = K._Pop();
      // cout << v << " " << endl;
      if(v == Szukany) break;
      for(unsigned int j = 1; j <= _V; ++j)
	if(_CzyKrawedz(v,j) && !Odwiedzone[j])
	  {
	    K._Push(j,K._Rozmiar());
	    Odwiedzone[j] = true;
	  }
     
    }
  delete [] Odwiedzone;
}
//******************************************************************
template <class Typ>
void Graf<Typ>::DFS(const int x,const int Wymagany)const
{
  //cout <<"szykany: " << Wymagany << endl;
  StosTab<int> S;
  bool *Odwiedzony =new bool[_V+1];
  for(unsigned int i = 0; i <= _V; ++i)
    Odwiedzony[i] = false;
  S._Push(x);
  Odwiedzony[x] = true;
  //cout << x << " : " << endl;
  if(x == Wymagany) return;
  while(!S.CzyPusty())
    {
      int k = S._Pop();
      // cout << k << " " << endl;
      if(k == Wymagany) break;
      for(unsigned int i = _V; i>0; --i)
	if(_CzyKrawedz(k,i) && !Odwiedzony[i])
	  {
	    S._Push(i);
	    Odwiedzony[i] = true;
	  }
    }
  delete [] Odwiedzony;
}
//******************************************************************
template <class Typ>
void Graf<Typ>:: _Zaladuj(unsigned int n)
{
  const unsigned int m = (n/2);
  for(unsigned int i = 1; i < n; ++i)
    {
      if(i < m)
	{
	  _DodajKrawedz(i,i+1);
	  _DodajKrawedz(i,m+i);
	  _DodajKrawedz(i,m+i+1);
	}
      if(i > m)
	_DodajKrawedz(i,i+1);
      
    }
}
//******************************************************************
template <class Typ>
void Graf<Typ>::_Wykonaj(unsigned int n)const
{
  const int m = n/2;
  this ->BFS(1,m);
}
//******************************************************************
template <class Typ>
void Graf<Typ>::_Zwolnij()
{
  this->Graf::~Graf();
}
//******************************************************************
template<class Typ>
void Graf<Typ>::_DodajWartoscWierzcholka(const unsigned int indeks,
					 const Typ Wartosc)
{
  _VMacierz[indeks] = Wartosc;
}
//******************************************************************
template<class Typ>
Typ Graf<Typ>::_ZwrocWartoscWierzcholka(const unsigned int indeks)const
{
  return _VMacierz[indeks];
}
//******************************************************************
template<class Typ>
unsigned int Graf<Typ>::_IloscKrawedzi()const
{
  return _E;
}
//******************************************************************
