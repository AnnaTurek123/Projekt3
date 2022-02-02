#include <iostream>

using namespace std;

int main()
{
    int n, i=1; int M_PI;
    double sum = 0, m=1, zn=1;
    cout << "podaj n" << endl;
    cin >> n;
    while ( i <=n)
    {
        sum = sum + zn/m;
        zn=-zn;
        m=m+2;
        i=i+1;
    }
    sum = 4* sum;
    cout << "pi=" << sum << endl;
    cout << "pi=" << M_PI << endl;



    return 0;
}

//wyznaczenie przybli¿onej wartoœci pi
