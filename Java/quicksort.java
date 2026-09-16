public class quicksort {
    public static int partition(int[] a, int l, int h) {
        int pvt = a[h];
        int j = l - 1, k;
        for (k = l; k < h; k++) {
            if (a[k] < pvt) {
                j += 1;
                swap(a, j, k);
            }
        }
        swap(a, j + 1, h);
        return j + 1;
    }

    public static void swap(int[] a, int j, int k) {
        int temp;
        temp = a[j];
        a[j] = a[k];
        a[k] = temp;
    }

    public static void qcksort(int[] a, int l, int h) {
        int pi;
        if (l < h) {
            pi = partition(a, l, h);
            qcksort(a, l, pi - 1);
            qcksort(a, pi + 1, h);
        }
    }

    public static void printArr(int[] a) {
        int i, s = a.length;
        for (i = 0; i < s; i++) {
            System.out.print(a[i] + " ");
        }
    }

    public static void main(String[] args) {
        int[] a = { 10, 7, 8, 9, 1, 5 };
        int s = a.length;
        System.out.println("El Arreglo antes de ser ordenado");
        printArr(a);
        qcksort(a, 0, s - 1);
        System.out.println("El Arreglo despues de ser ordenado");
        printArr(a);

    }
}