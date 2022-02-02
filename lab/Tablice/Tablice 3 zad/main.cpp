#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int LENGTH = 10;
    float A[LENGTH];
    srand( time(NULL));

    for(int i=0; i<LENGTH; i++)
    {

        A[i] = (rand() % 1000-500)/11,0;
    }
    for (int i =0; i< LENGTH; i++)
    {
        //cout << A[i] << " ";
        //cout << A[i] << endl;
        cout << "A[" << i << " ]=" << A[i] << endl;
    }

    float maks = A[0];
    for (int i=0; i< LENGTH-1;i++)
    {
        if(A[i+1] > maks)
        {
            maks= A[i+1];
        }
    }
    cout << "a) maks = " << maks << endl;

    return 0;
}
