#pragma once
using namespace std;
#include "Vector.h"
#include <ostream>
template < class ValType >
class TMatrix : public TVector< TVector<ValType> >
{
public:
  TMatrix (int s = 10);
  TMatrix (const TMatrix & mt);
  TMatrix (const TVector < TVector < ValType >> &mt);
  TMatrix & operator== (const TMatrix & mt);
  TMatrix & operator= (const TMatrix & mt);
  TMatrix & operator+ (const TMatrix & mt);
  TMatrix & operator- (const TMatrix & mt);
  TMatrix & operator* (const TMatrix & mt);
  friend std::istream& operator>>(istream &in, TMatrix &mt);
  friend std::ostream& operator<<(ostream &out, const TMatrix &mt);
};
