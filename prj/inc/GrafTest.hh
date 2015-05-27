#ifndef GRAFTEST_HH
#define GRAFTEST_HH
#include "Itest.hh"
#include "Graf.hh"
class GrafTest:public Itest, public Graf
{
public:
  void _Wykonaj(const unsigned int n){}
  void _Zwolnij(){}
  void _Zaladuj(const unsigned int n)
  {
    for(unsigned int i = 1; i <= n; ++i)
      {
	if(i<n/2)
	  {
	    this ->_DodajKrawedz(i,i+1);
	    this ->_DodajKrawedz(i,(n/2)+i);
	    this ->_DodajKrawedz(i,(n/2)+i+1);
	  }
	else
	  {
	    _DodajKrawedz(i,i+1);
	  }
      }
  }

 

};
#endif
