#include <iostream>

using namespace std;

int main()
{
    int k=1, s=1, n;
    cout<<"Podaj n " << endl;
    cin >> n;

    while (k<n)
    {
        k = k+1;
        s = k*s;
    }
    cout << "silnia=" << s;
    return 0;
}

// program do obliczania silni z pêtl¹ while
