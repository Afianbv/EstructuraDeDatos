#include <iostream>
using namespace std;
int escojio(x, y)
{
    for
        arr,
}
int main()
{
    int x, y;
    int mapa[8][8] =
        {
            {2, 0, 2, 0, 2, 0, 2, 0},
            {0, 2, 0, 2, 0, 2, 0, 2},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 1, 0, 1, 0, 1, 0},
            {0, 1, 0, 1, 0, 1, 0, 1}};
    cout << "DAMAS" << endl;
    cout << "PARA JUGAR DEBERA ESCOJER X E Y DE SU PIEZA QUE QUIERE MOVER" << endl;
    cout << "YA SELECCIONADA SU PIEZA DEBE ESCOJER ENTRE 1 Y 4 PARA SABER A QUE ESQUINA QUIERE MOVERSE" << endl;
    cout << "1   2" << endl;
    cout << "  x  " << endl;
    cout << "3   4" << endl;
    cout << "__________" << endl;
    for (x = 0; x < 8; x++)
    {
        for (y = 0; y < 8; y++)
        {
            cout << "|";
            cout << mapa[x][y];
            cout << "|";
        }
        cout << endl;
    }
    cout << "----------";
}