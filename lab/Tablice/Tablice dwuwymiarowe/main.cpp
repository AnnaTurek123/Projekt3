#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
   srand(time(NULL));
   const int M = 5;
   const int N = 5;
   int A[M][N];
   int B[M][N];
   for (int i=0; i<M; i++)
   {
       for(int j=0; j<N; j++)
       {

           A[i][j] = rand() % 10;
           cout << A[i][j] << " ";

       }
       cout << endl;
   }
cout << "B: " << endl;
for(int i=0; i<M; i++)
{

    for(int j=0; j<M; j++)
    {
        B[j][i]= A[i][j];
    }

    // wyœwietlanie i transpozycja

}
cout << "B: " << endl;
for(int i=0; i<N; i++)
{
    for(int j=0; j<M; j++)
    {
        cout << B[i][j] << " ";
    }
    cout << endl;
}
    int suma = 0;
    for(int i=0; i< N; i++)
{
    for(int j=0; j<N; j++)
    {
        suma= suma + A[i][j];
    }
}
cout << "suma el =" << suma;

//dodawanie

//œrednia na przek¹tnej zrobic



    return 0;
}
