#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    TMatrix<int> a(5), b(5), c(5);
    int i,j;
    cout <<" Triangular matrix test "<< endl;
    for (i = 0; i < 5; i++)
    for (j = i; i<5; j++)
    {
        a[i][j] = i * 10 + j;
        b[i][j] = (i * 10 + j)*100;
    }
    c=a+b;
    cout<<"Matrix a = " <<endl << a << endl;
    cout<<"Matrix b = " <<endl << b << endl;
    cout<<"Matrix c = " <<endl << c << endl;
}
