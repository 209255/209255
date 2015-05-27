#ifndef ITEST_HH
#define ITEST_HH

class Itest
{
public:
  virtual void _Wykonaj(const unsigned int n) = 0;
  virtual void _Zwolnij() = 0;
  virtual void _Zaladuj(const unsigned int n)=0;
};
#endif
