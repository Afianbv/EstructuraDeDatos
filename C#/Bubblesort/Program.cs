using System;
class Program
{
    static void BubleSort(int[] a)
    {
        Boolean isswapped;
        int j, i;
        int s = a.Length;
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
    static void Main(string[] args)
    {
        int[] a = { 15, 16, 11, 13, 14 };
        int j;
        int s = a.Length;
        Console.WriteLine("Antes de ordenar los elementos del array son: ");
        for (j = 0; j < s; j++)
        {
            Console.Write(a[j] + " ");
        }
        Console.Write("\n");
        BubleSort(a);
        Console.WriteLine("Despues de ordenar los elementos del array son:");
        for (j = 0; j < s; j++)
        {
            Console.Write(a[j] + " ");
        }
    }
}
