#include <iostream>
using namespace std;
void seleccion(int a[], int s)
{
    int j, i, temp, small;
    for (i = 0; i < s; i++)
    {
        small = i;
        for (j = i + 1; j < s; j++)
        {
            if (a[small] > a[j])
            {
                small = j;
            }
        }
        temp = a[i];
        a[i] = a[small];
        a[small] = temp;
    }
}
void printArr(int a[], int s)
{
    int j;
    for (j = 0; j < s; j++)
    {
        cout << a[j] << " ";
    }
}
int main()
{
    int a[] = {65, 26, 13, 23, 12};
    int s = sizeof(a) / sizeof(a[0]);
    cout << " Arreglo antes de ser ordenado" << endl;
    printArr(a, s);
    seleccion(a, s);
    cout << endl;
    cout << " Arreglo despues de ser ordenado" << endl;
    printArr(a, s);
}