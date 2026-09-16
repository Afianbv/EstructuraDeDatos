public class seleccion {
    public static void selec(int[] a) {
        int s = a.length, i, j, small, temp;
        for (i = 0; i < s; i++) {
            small = i;
            for (j = i + 1; j < s; j++) {
                if (a[small] > a[j]) {
                    small = j;
                }
            }
            temp = a[i];
            a[i] = a[small];
            a[small] = temp;
        }
    }

    public static void printArr(int[] a) {
        int i, s = a.length;
        for (i = 0; i < s; i++) {
            System.out.print(a[i] + " ");
        }
    }

    public static void main(String[] args) {
        int[] a = { 65, 26, 13, 23, 12 };
        System.out.println("Arreglo antes de ser ordenado");
        printArr(a);
        selec(a);
        System.out.println("Arreglo despues de ser ordenado");
        printArr(a);
    }

}