#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int * createTable(int n)
{
    int * tab = new int[n];
    srand(time(0));
    for(int i=0; i<n; i++)
    {
        tab[i] = rand() % 15 - 7;
    }
    return tab;
}

int findMod(int*tab, int n)
{
    int maxAbs = abs(tab[0]);
    for(int i=0;i<n;i++)
    {
        if(abs(tab[i]) > maxAbs)
        {
            maxAbs = abs(tab[i]);
        }
    }
    return maxAbs;
}

float calcAvg(int * tab, int n, int x)
{
    float suma=0;
    int licznik=0;
    for (int i=0; i<n; i++)
    {
        if(tab[i] > x)
        {
            suma +=tab[i];
            licznik++;
        }
    }
    if(licznik>0)
    {
        suma = suma/licznik;
    }
    return suma;
}

int countElements(int * tab, int n)
{
    int licznik=0;
    for(int i=0; i<n; i++)
    {
        if(tab[i]== tab[0])
        {
            licznik++;
        }
    }
    return licznik;
}

void rewriteFile()
{
    ifstream plik("D:/lorum ipsum.txt");
    ofstream wy("D:/we.txt");
    if(plik.good())
    {
        char znak;
        while(!plik.eof())
        {
            plik.get(znak); //plik >> znak;
            if(znak >= 65 && znak <=90)
            {
                znak+=32;
            }
            else if (znak >= 97 && znak <= 122)
            {
                znak-=32;
            }
            wy<<znak;
        }
        plik.close();
        wy.close();
    }
    else
    {
        cout << " NIe uda³o sie wczytac pliku" << endl;
    }
}
void saveMult()
{
    ifstream liczby("D:/liczby.txt");
    ofstream dod("D:/dodawanie.txt");
    ofstream ujem("D:/ujemne.txt");

    if(liczby.good())
    {
        float a, b, il;
        while(liczby >> a >> b)
        {
            il = a * b;
            if(il>=0)
                dod << il << endl;
            else
                ujem << il << endl;
        }
        liczby.close();
        dod.close();
        ujem.close();
    }
}

void calcAvgFromFile()
{
    float  suma;
    ifstream lista("D:/lista.txt");
    int tab[100], i=0;
    if(lista.good())
    {
        while(lista >> tab[i])
        {
            suma += tab[i];
            i++;
            cout << "suma =" << suma << endl;
            cout << "i=" << i << endl;
        }
        if(i > 0)
            suma = suma/i;
        cout << "srednia" << suma << endl;

    }
}


int main()
{
   int*wsk;
   int tabSize = 10;

   wsk = createTable(tabSize);
   for(int i=0; i<tabSize;i++)
   {
       cout << "*(wsk+" << i << ")=" << *(wsk+i) << endl;
   }

   cout << findMod(wsk, tabSize) << "  wartosc maksymalna wsrod modulow elementow tablicy" << endl;
   cout << calcAvg(wsk, tabSize, 2) << "  srednia z elementow" << endl;
   cout <<countElements(wsk, tabSize) << "  ilosc elementow takich samych jak pierwszy" << endl;
   rewriteFile();
   saveMult();

   delete [] wsk;
    return 0;
}
