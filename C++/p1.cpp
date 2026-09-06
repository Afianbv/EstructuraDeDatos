#include <iostream>
using namespace std;

int main()
{
    int r = 3, x = 0, y = 0, k = 0;
    int arr[9];
    int arr2[3][3] =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
    for (x = 0; x < r; x++)
    {
        for (y = 0; y < r; y++)
        {
            arr[k] = arr2[x][y];
            k++;
        }
    }
    cout << ("Los elementos del array bidimensional son: ") << endl;
    for (x = 0; x < r; x++)
    {
        for (y = 0; y < r; y++)
        {
            cout << (arr2[x][y]);
        }
        cout << endl;
    }
    cout << ("Los elementos del array unidimensional son: ") << endl;
    for (y = 0; y < r; y++)
    {
        for (x = 0; x < r; x++)
        {
            cout << (arr[x * r + y]);
        }
    }
}