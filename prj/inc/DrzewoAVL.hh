#ifndef DRZEWOAVL_HH
#define DRZEWOAVL_HH
#include"WezelAVL.hh"
#include<cstring>
template<class Typ>
class DrzewoAVL
{
private:

//**************************************************************************
  WezelAVL<Typ>* _Korzen;
//**************************************************************************
  int Wysokosc(WezelAVL<Typ> *W)const 
  {
    int n;
    if(W == NULL) return -1;
    else
      {
	n = W->_Wysokosc;
	return n;
      }
  }
  int max(int l,int p)
  {
    return((l > p) ? l: p);
  }
//**************************************************************************
  void RotacjaPrawa(WezelAVL<Typ> *&W)
  {
    WezelAVL<Typ> *Temp = W ->_Prawy;
    W ->_Prawy = Temp ->_Lewy;
    Temp ->_Lewy = W;
    W ->_Wysokosc = max(Wysokosc(W ->_Lewy),Wysokosc(W->_Prawy)) +1;
    W = Temp;
    Temp ->_Wysokosc = max(W ->_Wysokosc,Wysokosc(Temp ->_Prawy))+1;
  }
//**************************************************************************
  void RotacjaLewa(WezelAVL<Typ> *&W)
  {
    WezelAVL<Typ> *Temp = W ->_Lewy;
    W ->_Lewy = Temp ->_Prawy;
    Temp ->_Prawy = W;
    W ->_Wysokosc = max(Wysokosc(W ->_Lewy),Wysokosc(W ->_Prawy))+1;
    W = Temp;
    Temp ->_Wysokosc = max(Wysokosc(Temp->_Lewy),W ->_Wysokosc)+1;
		       
  }
//**************************************************************************
  void RotacjaRL(WezelAVL<Typ> *&W)
  {
    cout << "wewRL" << endl;
    RotacjaPrawa(W->_Lewy);
    RotacjaLewa(W);
  }
//**************************************************************************
  void RotacjaLR(WezelAVL<Typ> *&W)
  {
    cout << "wewLR" << endl;
    RotacjaLewa(W->_Prawy);
    RotacjaPrawa(W);
  }
//**************************************************************************
/*
 void DodajGalaz(WezelAVL<Typ> *&W,const Typ n)
  {
    if(W == NULL)
      {
	W = new WezelAVL<Typ>(n);
      }
    else
      {
	Dodaj(n,W);
      }
      }*/
//**************************************************************************

public:

//**************************************************************************
  virtual ~DrzewoAVL()
  {
    delete _Korzen;
    _Korzen = NULL;
  }
//**************************************************************************
  DrzewoAVL()
  {
    _Korzen = NULL;
  }
//**************************************************************************
  DrzewoAVL(const Typ W)
  {
    _Korzen = new WezelAVL<Typ>(W);
  } 
//**************************************************************************
  WezelAVL<Typ> *Wyszukaj (WezelAVL<Typ> *S, const Typ Wartosc)const 
  {
    if(S ->_Wartosc == Wartosc)
      return S;
    else if( S ->_Wartosc < Wartosc && S ->_Prawy != NULL)
      return Wyszukaj(S ->_Prawy,Wartosc);
    else if( S ->_Wartosc > Wartosc && S ->_Lewy != NULL)
      return Wyszukaj(S ->_Lewy,Wartosc);
    else
      return NULL;
  }
  void Dodaj(const Typ Wartosc)
  {
    Dodaj(Wartosc,_Korzen);
  }
//**************************************************************************  
  void Dodaj(Typ Wartosc,WezelAVL<Typ> *&S)
  {
    if(S == NULL)
      {
	S = new WezelAVL<Typ>(Wartosc);
      }
    else
      {
	if(Wartosc < S->_Wartosc)
	  {
	    Dodaj(Wartosc,S->_Lewy);
	    if((Wysokosc(S->_Lewy) - Wysokosc(S->_Prawy)) == 2)
	      {
		cout << "lewa"<< endl;
		if(Wartosc < S->_Lewy->_Wartosc)
		  {
		    cout <<"rotacjaLewa" << endl;
		    RotacjaLewa(S);
		  }
		else
		  {
		    cout<<"rotacjaRL" << endl;
		    RotacjaRL(S);
		  }
	      }
	    else if(S->_Wartosc < Wartosc)
	      {
		Dodaj(Wartosc,S->_Prawy);
		if((Wysokosc(S->_Prawy) - Wysokosc(S->_Lewy)) == 2)
		  {
		    cout<<"Prawa" << endl;
		    if(Wartosc > S->_Prawy->_Wartosc)
		      {
			cout << "RotacjaPrawa" <<endl;
			RotacjaPrawa(S);
		      }
		    else
		      {
			cout <<"RotacjaLR" << endl;
			RotacjaLR(S);
		      }
		  }
	      }
	  }
      }
    S ->_Wysokosc = max(Wysokosc(S ->_Lewy),Wysokosc(S->_Prawy)) +1;
  }  
//**************************************************************************
  void Usun(WezelAVL<Typ> *S){}
  void PrzejdzDrzewo(WezelAVL<Typ> *S)
  {
    if(S ->_Lewy != NULL)
      PrzejdzDrzewo(S->_Lewy);
    
    cout << S ->_Wartosc << endl;
    
    if(S->_Prawy != NULL)
      PrzejdzDrzewo(S->_Prawy);
  }
  WezelAVL<Typ> *_ZwrocKorzen() {return _Korzen;}
  void PreOrder(std::ostream &out,WezelAVL<Typ> pre)const
  {
    if(pre !=NULL)
      {
	out << pre->_Wartosc << "[label=\"" << pre->_Wartosc
	    <<"\\n" << Wysokosc(pre) << "\];\n";
      }
  }
  void Pokaz()const
  {
    Pokaz(_Korzen);
  }
    void Pokaz(WezelAVL<Typ> *W)const
    {
      if(W !=NULL)
	{
	  cout << " " << W->_Wartosc << " ";
	  Pokaz(W ->_Lewy);
	  Pokaz(W->_Prawy);
	}
    }
};
#endif
