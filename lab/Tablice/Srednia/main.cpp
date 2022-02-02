#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int LENGTH = 5;
    float A[LENGTH];
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
    float suma =0.0;
    float srednia = 0.0;
    //int licznik 0;

    for(int i=0; i< LENGTH; i++)
    {
        if(A[i] > 0.5)
        {
            suma = suma + A[i];
            srednia = suma / LENGTH;
        }
    }
    //cout << "b) maksAbs = " << maksAbs << endl;
    cout << suma << endl;
    cout << srednia << endl;

    return 0;
}

//œrednia i suma


