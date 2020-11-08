#include "Vector.h"
#include "Matrix.h"
template <class ValType>
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
    if (this != &mt)
    {
        if (Size != mt.Size)
        {
            delete[] pVector;
            pVector = new TVector<ValType> [mt.Size];
        }
        Size = mt.Size;
        StartIndex = mt.StartIndex;
        for (int i=0; i< Size; i++)
        pVector[i] = mt.pVector[i];
    }
    return *this;
}
