function Bubblesort(a) {
    let s = a.length;
    for (i = 0; i < s; i++) {
        isSwapped = false;
        for (j = 0; j < s - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                [a[j], a[j + 1]] = [a[j + 1], a[j]];
                isSwapped = true;
            }
        }
        if (isSwapped == false) {
            break;
        }
    }
}
let a = [15, 16, 11, 13, 14];
console.log("Antes de ordenar los elementos del array son:");
for (j = 0; j < 5; j++) {
    process.stdout.write(a[j] + " ");
}
Bubblesort(a)
console.log();
console.log("Despues de ordenar los elementos del array son:");
for (j = 0; j < 5; j++) {
    process.stdout.write(a[j] + " ");
}
