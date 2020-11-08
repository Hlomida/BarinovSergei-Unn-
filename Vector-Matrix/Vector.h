#pragma once
using namespace std;
#include <ostream>
template <class ValType>
class TVector
{
    protected:
    ValType *pVector;
    int Size;
    int StartIndex;
    public:
    TVector(int s = 10, int si = 0);
    TVector(const TVector &v);
    ~TVector();
    int GetSize() {return Size;}
    int GetStartIndex() {return StartIndex;}
    ValType& GetValue (int pos);
    ValType& operator[] (int pos);
    int operator== (const TVector &v);
    TVector& operator= (const TVector &v);
    TVector operator+ (const ValType &val);
    TVector operator- (const ValType &val);
    TVector operator* (const ValType &val);
    TVector operator+ (const TVector &v);
    TVector operator- (const TVector &v);
    TVector operator* (const TVector &v);
    friend std::istream& operator>>(istream &in, TVector &v);
    friend std::ostream& operator<<(ostream &out, const TVector &v);
};