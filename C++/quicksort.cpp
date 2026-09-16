#include <iostream>
using namespace std;

void swapVal(int a[], int j, int k)
{
    int temp = a[j];
    a[j] = a[k];
    a[k] = temp;
}

int partition(int a[], int l, int h)
{
    int pvt = a[h];
    int j = l - 1;
    for (int k = l; k < h; k++)
    {
        if (a[k] < pvt)
        {
            j += 1;
            swapVal(a, j, k);
        }
    }
    swapVal(a, j + 1, h);
    return j + 1;
}

void qcksort(int a[], int l, int h)
{
    if (l < h)
    {
        int pi = partition(a, l, h);
        qcksort(a, l, pi - 1);
        qcksort(a, pi + 1, h);
    }
}

void printArr(int a[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int a[] = {10, 7, 8, 9, 1, 5};
    int s = sizeof(a) / sizeof(a[0]);

    cout << "El Arreglo antes de ser ordenado: " << endl;
    printArr(a, s);
    cout << endl;

    qcksort(a, 0, s - 1);

    cout << "El Arreglo despues de ser ordenado: " << endl;
    printArr(a, s);
    cout << endl;

    return 0;
}