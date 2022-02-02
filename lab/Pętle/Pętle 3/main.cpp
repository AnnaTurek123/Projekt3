#include <iostream>

using namespace std;


int main()
{
    int s=1, n;
    cout << " Podaj n " << endl;
    cin >> n;
    for (int k=1; k<=n; k++)
    {
        s=k*s;
    }
    cout << " silnia=" << s;
    return 0;
}

//program do obliczania silni
