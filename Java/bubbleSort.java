public class bubbleSort{
    public static void bublesort(int[] a){
        int s = a.length,i,j;
        Boolean isSwapped;
        int temp;
        for (i=0;i<s;i++){
            isSwapped = false;
            for (j=0;j<s-i-1;j++){
                if (a[j]>a[j+1]){
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    isSwapped=true;
                }
            }
            if(isSwapped==false){
                break;
            }
        }
    }
    public static void main(String[] args){
        int j;
        int[] a = {15,16,11,13,14};
        System.out.print("Ante de ordenar los elementos del array son: ");
        for (j=0;j<5;j++){
            System.out.print(a[j] + " ");
        }
        System.out.println();
        bublesort(a);
        System.out.print("Despues de ordenar los elementos del array son: ");
        for (j=0;j<5;j++){
            System.out.print(a[j] + " ");
        }
    }
}