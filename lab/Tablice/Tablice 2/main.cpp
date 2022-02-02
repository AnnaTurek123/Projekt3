#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int LENGTH = 10;
    int A[LENGTH];
    srand( time(NULL));

    for(int i=0; i<LENGTH; i++)
    {
        //4_1_a
        //cout << "Podaj wartoœæ elementu A[" << i << "] :" << endl;
        //cin >> A[i];
        //4_1_b
        //A[i] = i*10+1;
        //4_i_c

        A[i] = rand() % 100-50;
    }
    for (int i =0; i< LENGTH; i++)
    {
        //cout << A[i] << " ";
        //cout << A[i] << endl;
        cout << "A[" << i << " ]=" << A[i] << endl;
    }

    return 0;
}
