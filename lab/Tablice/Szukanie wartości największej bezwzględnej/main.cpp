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
    cout << "b) maksAbs = " << maksAbs << endl;

    return 0;
}
