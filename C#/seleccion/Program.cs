using System;
class Program
{
    static void seleccion(int[] a)
    {
        int j, i, small = 0, temp;
        int s = a.Length;
        for (i = 0; i < s; i++)
        {
            small = i;
            for (j = i + 1; j < s; j++)
            {
                if (a[small] > a[j])
                {
                    small = j;
                }
            }
            temp = a[i];
            a[i] = a[small];
            a[small] = temp;
        }
    }
    static void printArr(int[] a)
    {
        int j;
        int s = a.Length;
        for (j = 0; j < s; j++)
        {
            Console.Write(a[j] + " ");
        }
    }
    static void Main(String[] arg)
    {
        int[] a = { 65, 26, 13, 23, 12 };
        Console.WriteLine("Arreglo antes de ser ordenado: ");
        printArr(a);
        seleccion(a);
        Console.WriteLine("Arreglo despues de ser ordenado: ");
        printArr(a);

    }
}
