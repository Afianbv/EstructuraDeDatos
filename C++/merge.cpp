#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, int l, int m, int r)
{
    int a1 = m - l + 1;
    int a2 = r - m;
    vector<int> L(a1);
    vector<int> R(a2);
    for (int j = 0; j < a1; j++)
    {
        L[j] = a[l + j];
    }
    for (int k = 0; k < a2; k++)
    {
        R[k] = a[m + 1 + k];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < a1 && j < a2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i = i + 1;
        }
        else
        {
            a[k] = R[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i < a1)
    {
        a[k] = L[i];
        i = i + 1;
        k = k + 1;
    }
}

void mergeSort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    vector<int> a = {39, 28, 44, 11};
    int s = a.size();
    cout << "Antes de ordenar el arreglo: " << endl;
    for (int j = 0; j < s; j++)
    {
        cout << a[j] << " ";
    }
    mergeSort(a, 0, s - 1);
    cout << "\nDespues de ordenar el arreglo: " << endl;
    for (int j = 0; j < s; j++)
    {
        cout << a[j] << " ";
    }
    return 0;
}