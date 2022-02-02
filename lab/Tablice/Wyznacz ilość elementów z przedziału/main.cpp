


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int LENGTH = 5;
    int A[LENGTH];
    srand( time(NULL));

    for(int i=0; i<LENGTH; i++)
    {

        A[i] = (rand() % 10);
        cout << "A[" << i << " ]=" << A[i] << endl;
    }

    float maksAbs = abs(A[0]);
    for (int i=0; i< LENGTH-1;i++)
    {
        if(abs(A[i+1]) > maksAbs)
        {
            maksAbs= abs(A[i+1]);
        }
    }
    //float suma =0.0;
    //float srednia = 0.0;
    int licznik_prze = 0;

    for(int i=0; i< LENGTH; i++)
    {
        if(A[i] >= 5&& A[i] < 10)
        {
            licznik_prze++;
        }
    }
    //cout << "b) maksAbs = " << maksAbs << endl;
    //cout << suma << endl;
   // cout << srednia << endl;
   //cout << "liczba parzystych =" << licznik_parz <<endl;
   cout << "liczb elementów z przedzia³u <5;10):  " << licznik_prze << endl;

    return 0;
}
