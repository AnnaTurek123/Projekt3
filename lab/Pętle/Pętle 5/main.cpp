#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    for (int i=1; i<100;i=i+2)
    {
        sum=sum+i;
    }
        cout << sum << endl;
    return 0;
}

// program kt�ry sumuje liczby nieparzyste z przedzia�u od 1 do 100
