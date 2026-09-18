#include <iostream>
using namespace std;

// mapa
void imprimirMapa(char a[8][8])
{
    int i, j;
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for (i = 0; i < 8; i++)
    {
        cout << i << " ";
        for (j = 0; j < 8; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
bool masataque(char a[8][8], int x, int y, bool turno) // comprueba si puede volver a atacar o no :v
{
    if (turno == true || a[x][y] == 'B')
    {
        if (x - 2 >= 0 && y - 2 >= 0)
        {
            if (turno == true && (a[x - 1][y - 1] == 'b' || a[x - 1][y - 1] == 'B') && a[x - 2][y - 2] == '.')
                return true;
            if (turno == false && (a[x - 1][y - 1] == 'n' || a[x - 1][y - 1] == 'N') && a[x - 2][y - 2] == '.')
                return true;
        }
        // Diagonal arriba-derecha
        if (x - 2 >= 0 && y + 2 <= 7)
        {
            if (turno == true && (a[x - 1][y + 1] == 'b' || a[x - 1][y + 1] == 'B') && a[x - 2][y + 2] == '.')
                return true;
            if (turno == false && (a[x - 1][y + 1] == 'n' || a[x - 1][y + 1] == 'N') && a[x - 2][y + 2] == '.')
                return true;
        }
    }
    if (turno == false || a[x][y] == 'N')
    {
        // Diagonal abajo-izquierda
        if (x + 2 <= 7 && y - 2 >= 0)
        {
            if (turno == false && (a[x + 1][y - 1] == 'n' || a[x + 1][y - 1] == 'N') && a[x + 2][y - 2] == '.')
                return true;
            if (turno == true && (a[x + 1][y - 1] == 'b' || a[x + 1][y - 1] == 'B') && a[x + 2][y - 2] == '.')
                return true;
        }
        // Diagonal abajo-derecha
        if (x + 2 <= 7 && y + 2 <= 7)
        {
            if (turno == false && (a[x + 1][y + 1] == 'n' || a[x + 1][y + 1] == 'N') && a[x + 2][y + 2] == '.')
                return true;
            if (turno == true && (a[x + 1][y + 1] == 'b' || a[x + 1][y + 1] == 'B') && a[x + 2][y + 2] == '.')
                return true;
        }
    }
    return false;
}
void coronar(char a[8][8], int x, int y) // le subo rango
{
    if (a[x][y] == 'n' && x == 0)
    {
        a[x][y] = 'N';
    }
    if (a[x][y] == 'b' && x == 7)
    {
        a[x][y] = 'B';
    }
}
void seguirComiendo(char a[8][8], int &x, int &y, bool turno)
{
    while (masataque(a, x, y, turno) == true)
    {
        imprimirMapa(a);
        int dir;
        int saltoX = -1, saltoY = -1, enemigoX = -1, enemigoY = -1;
        if (a[x][y] == 'N' || a[x][y] == 'B')
        {
            cout << "A donde desea moverla? [1]Arriba-Izq [2]Arriba-Der [3]Abajo-Izq [4]Abajo-Der: ";
            cin >> dir;
            if (dir == 1)
            {
                enemigoX = x - 1;
                enemigoY = y - 1;
                saltoX = x - 2;
                saltoY = y - 2;
            }
            if (dir == 2)
            {
                enemigoX = x - 1;
                enemigoY = y + 1;
                saltoX = x - 2;
                saltoY = y + 2;
            }
            if (dir == 3)
            {
                enemigoX = x + 1;
                enemigoY = y - 1;
                saltoX = x + 2;
                saltoY = y - 2;
            }
            if (dir == 4)
            {
                enemigoX = x + 1;
                enemigoY = y + 1;
                saltoX = x + 2;
                saltoY = y + 2;
            }
        }
        else
        {
            cout << "A donde desea moverla? [1]Izquierda [2]Derecha: ";
            cin >> dir;
            if (turno == true) // Negra
            {
                if (dir == 1)
                {
                    enemigoX = x - 1;
                    enemigoY = y - 1;
                    saltoX = x - 2;
                    saltoY = y - 2;
                }
                if (dir == 2)
                {
                    enemigoX = x - 1;
                    enemigoY = y + 1;
                    saltoX = x - 2;
                    saltoY = y + 2;
                }
            }
            else // Blanca
            {
                if (dir == 1)
                {
                    enemigoX = x + 1;
                    enemigoY = y - 1;
                    saltoX = x + 2;
                    saltoY = y - 2;
                }
                if (dir == 2)
                {
                    enemigoX = x + 1;
                    enemigoY = y + 1;
                    saltoX = x + 2;
                    saltoY = y + 2;
                }
            }
        }
        if (saltoX >= 0 && saltoX <= 7 && saltoY >= 0 && saltoY <= 7)
        {
            bool esEnemigo = false;
            if (turno == true && (a[enemigoX][enemigoY] == 'b' || a[enemigoX][enemigoY] == 'B'))
                esEnemigo = true;
            if (turno == false && (a[enemigoX][enemigoY] == 'n' || a[enemigoX][enemigoY] == 'N'))
                esEnemigo = true;

            if (esEnemigo == true && a[saltoX][saltoY] == '.')
            {
                a[saltoX][saltoY] = a[x][y];
                a[x][y] = '.';
                a[enemigoX][enemigoY] = '.'; // Se la come
                x = saltoX;
                y = saltoY;
            }
            else
            {
                cout << "No puedes comer por ahi." << endl;
            }
        }
        else
        {
            cout << "Te sales del mapa." << endl;
        }
    }
}
void quiengana(char a[8][8], int &gano, bool &turno) // revisa si todavia tienen piezas
{
    int i, j;
    gano = 1;
    if (turno == true)
    {
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                if (a[i][j] == 'b' || a[i][j] == 'B')
                {
                    gano = 0;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                if (a[i][j] == 'n' || a[i][j] == 'N')
                {
                    gano = 0;
                }
            }
        }
    }
    turno = !turno; // Cambiar turno
}

void esunapieza(char a[8][8], int &x, int &y, bool turno)
{
    while (true)
    {
        cout << "Seleccione la pieza que quiere mover (fila y columna): ";
        cin >> x >> y;

        if (x < 0 || x > 7 || y < 0 || y > 7)
        {
            cout << "no existe." << endl;
        }
        else if (a[x][y] == '.')
        {
            cout << "No hay ninguna pieza en esa ubicacion." << endl;
        }
        else if (turno == true && (a[x][y] == 'b' || a[x][y] == 'B'))
        {
            cout << "Esa pieza es de tu oponente." << endl;
        }
        else if (turno == false && (a[x][y] == 'n' || a[x][y] == 'N'))
        {
            cout << "Esa pieza es de tu oponente." << endl;
        }
        else
        {
            break;
        }
    }
}

void movvalido(char a[8][8], int x, int y, bool turno)
{
    int dir;
    int error = 0;

    do
    {
        error = 0;
        int destX = -1, destY = -1;
        int saltoX = -1, saltoY = -1;

        if (a[x][y] == 'N' || a[x][y] == 'B')
        {
            cout << "Mover REY: [1]Arriba-Izq [2]Arriba-Der [3]Abajo-Izq [4]Abajo-Der: ";
            cin >> dir;

            if (dir == 1)
            {
                destX = x - 1;
                destY = y - 1;
                saltoX = x - 2;
                saltoY = y - 2;
            }
            else if (dir == 2)
            {
                destX = x - 1;
                destY = y + 1;
                saltoX = x - 2;
                saltoY = y + 2;
            }
            else if (dir == 3)
            {
                destX = x + 1;
                destY = y - 1;
                saltoX = x + 2;
                saltoY = y - 2;
            }
            else if (dir == 4)
            {
                destX = x + 1;
                destY = y + 1;
                saltoX = x + 2;
                saltoY = y + 2;
            }
            else
            {
                cout << "Opcion invalida." << endl;
                error = 1;
                continue;
            }
        }
        else
        {
            cout << "A donde desea moverla? [1]Izquierda [2]Derecha: ";
            cin >> dir;

            if (turno == true)
            {
                if (dir == 1)
                {
                    destX = x - 1;
                    destY = y - 1;
                    saltoX = x - 2;
                    saltoY = y - 2;
                }
                else if (dir == 2)
                {
                    destX = x - 1;
                    destY = y + 1;
                    saltoX = x - 2;
                    saltoY = y + 2;
                }
                else
                {
                    cout << "Opcion invalida." << endl;
                    error = 1;
                    continue;
                }
            }
            else
            {
                if (dir == 1)
                {
                    destX = x + 1;
                    destY = y - 1;
                    saltoX = x + 2;
                    saltoY = y - 2;
                }
                else if (dir == 2)
                {
                    destX = x + 1;
                    destY = y + 1;
                    saltoX = x + 2;
                    saltoY = y + 2;
                }
                else
                {
                    cout << "Opcion invalida." << endl;
                    error = 1;
                    continue;
                }
            }
        }

        if (destX < 0 || destX > 7 || destY < 0 || destY > 7)
        {
            cout << "Te sales del mapa." << endl;
            error = 1;
        }

        else if (a[destX][destY] == '.')
        {
            a[destX][destY] = a[x][y];
            a[x][y] = '.';
            coronar(a, destX, destY);
            break;
        }

        else if ((turno == true && (a[destX][destY] == 'n' || a[destX][destY] == 'N')) ||
                 (turno == false && (a[destX][destY] == 'b' || a[destX][destY] == 'B')))
        {
            cout << "Hay una pieza tuya en esa posicion." << endl;
            error = 1;
        }

        else
        {
            if (saltoX >= 0 && saltoX <= 7 && saltoY >= 0 && saltoY <= 7 && a[saltoX][saltoY] == '.')
            {
                a[saltoX][saltoY] = a[x][y];
                a[x][y] = '.';
                a[destX][destY] = '.';
                cout << "Comiste una pieza!" << endl;

                int nuevaFila = saltoX;
                int nuevaCol = saltoY;

                seguirComiendo(a, nuevaFila, nuevaCol, turno);

                coronar(a, nuevaFila, nuevaCol);
                break;
            }
            else
            {
                cout << "No puedes saltar esa pieza (bloqueado o fuera del mapa)." << endl;
                error = 1;
            }
        }

    } while (error == 1);
}

void moverpieza(char a[8][8], bool turno)
{
    int f, h;
    esunapieza(a, f, h, turno);
    movvalido(a, f, h, turno);
}

void guardarTablero(char a[8][8], char historial[200][8][8], int &totalTurnos)
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            historial[totalTurnos][i][j] = a[i][j];
        }
    }
    totalTurnos++;
}

int main()
{
    bool turno = false; // false = blancas true =negras
    int gano = 1;
    char historial[200][8][8];
    int totalTurnos = 0;

    char mapa[8][8] =
        {
            {'b', '.', 'b', '.', 'b', '.', 'b', '.'},
            {'.', 'b', '.', 'b', '.', 'b', '.', 'b'},
            {'b', '.', 'b', '.', 'b', '.', 'b', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', 'n', '.', 'n', '.', 'n', '.', 'n'},
            {'n', '.', 'n', '.', 'n', '.', 'n', '.'},
            {'.', 'n', '.', 'n', '.', 'n', '.', 'n'}};

    // Guardamos el tablero inicial como turno 0
    guardarTablero(mapa, historial, totalTurnos);

    cout << "JUEGO DE DAMAS" << endl;

    do
    {
        if (turno == true)
            cout << endl
                 << "Turno de negras" << endl;
        else
            cout << endl
                 << "Turno de blancas" << endl;

        imprimirMapa(mapa);
        moverpieza(mapa, turno);

        // Guardamos el tablero despues de que se movio
        guardarTablero(mapa, historial, totalTurnos);

        quiengana(mapa, gano, turno);

    } while (gano == 0);

    imprimirMapa(mapa);
    if (turno == false)
    {
        cout << "Felicidades ganaron las negras " << endl;
    }
    else
    {
        cout << "Felicidades ganaron las blancas" << endl;
    }

    // Preguntar si quiere reproducir los movimientos
    int respuesta;
    cout << endl
         << "Deseas reproducir todos los movimientos de la partida? [1] Si  [2] No: ";
    cin >> respuesta;

    if (respuesta == 1)
    {
        cout << endl
             << "PARTIDA" << endl;
        for (int k = 0; k < totalTurnos; k++)
        {
            if (k == 0)
            {
                cout << endl
                     << "inicio" << endl;
            }
            else
            {
                cout << endl
                     << " Movimiento " << k << endl;
            }
            imprimirMapa(historial[k]);
        }
        cout << endl;
    }

    return 0;
}
