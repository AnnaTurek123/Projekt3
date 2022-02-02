#include <iostream>

using namespace std;

int main()
{
    double A, b, x=1;
    int k=0;

    cout << "Podaj a" << endl;
    cin >> A;

    do
    {
        x = 0.5*(x + A/x);
        b = abs((x*x - A)/A);
        k++;
    }
    while(b > 5e-12);

    cout << "pierwiastek z A = " << x << endl;
    cout << "liczba kroków wynosi " << k << endl;
    return 0;
}

// obliczanie pierwiastka z liczby
