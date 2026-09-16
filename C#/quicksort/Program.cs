using System;

class Program
{
    static void Swap(int[] a, int j, int k)
    {
        int temp = a[j];
        a[j] = a[k];
        a[k] = temp;
    }

    static int Partition(int[] a, int l, int h)
    {
        int pvt = a[h];
        int j = l - 1;
        for (int k = l; k < h; k++)
        {
            if (a[k] < pvt)
            {
                j += 1;
                Swap(a, j, k);
            }
        }
        Swap(a, j + 1, h);
        return j + 1;
    }

    static void Qcksort(int[] a, int l, int h)
    {
        if (l < h)
        {
            int pi = Partition(a, l, h);
            Qcksort(a, l, pi - 1);
            Qcksort(a, pi + 1, h);
        }
    }

    static void PrintArr(int[] a)
    {
        int s = a.Length;
        for (int i = 0; i < s; i++)
        {
            Console.Write(a[i] + " ");
        }
    }

    static void Main(string[] args)
    {
        int[] a = { 10, 7, 8, 9, 1, 5 };
        int s = a.Length;

        Console.WriteLine("El Arreglo antes de ser ordenado: ");
        PrintArr(a);
        Console.WriteLine();

        Qcksort(a, 0, s - 1);

        Console.WriteLine("El Arreglo despues de ser ordenado: ");
        PrintArr(a);
        Console.WriteLine();
    }
}