#include "Vector.h"

template <class Valtype>
TVector <Valtype>& TVector<Valtype>::operator= (const TVector &v)
{
    if (this != &v)
    {
        if (Size != v.Size)
        {
            delete[] pVector;
            pVector = new Valtype[v.Size];
        }
        Size = v.Size;
        StartIndex = v.StartIndex;
        for(int i=0; i< Size; i++)
        pVector[i]=v.pVector[i];
    }
    return *this;
}
template <class ValType>
TVector<ValType> TVector<ValType>::operator+ (const TVector<ValType> &v)
{
    TVector temp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        temp.pVector[i] = pVector[i] + v.pVector[i];
    return temp;
}
