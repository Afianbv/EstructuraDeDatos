using System;

class Program
{
    static void Main()
    {
        int r = 3, x = 0, y = 0, k = 0;
        int[] arr = new int[9];
        int[,] arr2 =
        {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };
        for (x = 0; x < r; x++)
        {
            for (y = 0; y < r; y++)
            {
                arr[k] = arr2[x, y];
                k++;
            }
        }
        Console.WriteLine("Los elementos del array bidimensional son: ");
        for (x = 0; x < r; x++)
        {
            for (y = 0; y < r; y++)
            {
                Console.Write(arr2[x, y]);
            }
            Console.Write("\n");
        }
        Console.WriteLine("Los elementos del array unidimensional son: ");
        for (y = 0; y < r; y++)
        {
            for (x = 0; x < r; x++)
            {
                Console.Write(arr[x * r + y]);
            }
        }
    }
}