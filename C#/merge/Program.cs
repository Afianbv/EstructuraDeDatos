using System;

class Program
{
    static void merge(int[] a, int l, int m, int r)
    {
        int a1 = m - l + 1;
        int a2 = r - m;
        int[] L = new int[a1];
        int[] R = new int[a2];
        for (int j = 0; j < a1; j++)
        {
            L[j] = a[l + j];
        }
        for (int k = 0; k < a2; k++)
        {
            R[k] = a[m + 1 + k];
        }
        int i = 0;
        int j2 = 0;
        int k2 = l;
        while (i < a1 && j2 < a2)
        {
            if (L[i] <= R[j2])
            {
                a[k2] = L[i];
                i = i + 1;
            }
            else
            {
                a[k2] = R[j2];
                j2 = j2 + 1;
            }
            k2 = k2 + 1;
        }
        while (i < a1)
        {
            a[k2] = L[i];
            i = i + 1;
            k2 = k2 + 1;
        }
    }

    static void mergeSort(int[] a, int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;
            mergeSort(a, l, m);
            mergeSort(a, m + 1, r);
            merge(a, l, m, r);
        }
    }

    static void Main(string[] args)
    {
        int[] a = { 39, 28, 44, 11 };
        int s = a.Length;
        Console.WriteLine("Antes de ordenar el arreglo: ");
        for (int j = 0; j < s; j++)
        {
            Console.Write(a[j] + " ");
        }
        mergeSort(a, 0, s - 1);
        Console.WriteLine("\nDespues de ordenar el arreglo: ");
        for (int j = 0; j < s; j++)
        {
            Console.Write(a[j] + " ");
        }
    }
}