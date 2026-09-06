public class p1 {
    public static void main() {
        int r = 3, x = 0, k = 0, y = 0;
        int[] arr = new int[9];
        int[][] arr2 = {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 }
        };
        for (x = 0; x < r; x++) {
            for (y = 0; y < r; y++) {
                arr[k] = arr2[x][y];
                k++;
            }
        }
        System.out.println("Los elementos del array bidimensional son: ");
        for (x = 0; x < r; x++) {
            for (y = 0; y < 3; y++) {
                System.out.print(arr2[x][y]);
            }
            System.out.println();
        }
        System.out.print("Los elementos del array unidimensinal son: ");
        for (y = 0; y < r; y++) {
            for (x = 0; x < r; x++) {
                System.out.print(arr[x * r + y]);
            }
        }
    }
}