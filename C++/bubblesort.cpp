#include <iostream>
using namespace std;
void bublesort(int a[], int s)
{
    int j, i;
    bool isswapped;
    int temp;
    for (j = 0; j < s; j++)
    {
        isswapped = false;
        for (i = 0; i < s - j - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                isswapped = true;
            }
        }
        if (isswapped == false)
        {
            break;
        }
    }
}
int main()
{
    int j;
    int a[] = {15, 16, 11, 13, 14};
    int s = sizeof(a) / sizeof(a[0]);
    cout << "Antes de ordenar los elementos del array son: " << endl;
    for (j = 0; j < 5; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;
    bublesort(a, s);
    cout << "Despues de ordenar los elementos del array son: " << endl;
    for (j = 0; j < 5; j++)
    {
        cout << a[j] << " ";
    }
}