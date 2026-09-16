function seleccion(a) {
    let s = a.length;
    for (i = 0; i < s; i++) {
        let small = i;
        for (j = i + 1; j < s; j++) {
            if (a[small] > a[j]) {
                small = j;
            }
        }
        [a[i], a[small]] = [a[small], a[i]];
    }
}
function printArr(a) {
    let s = a.length;
    for (i = 0; i < s; i++) {
        process.stdout.write(a[i] + " ");
    }
}
let a = [65, 26, 13, 23, 12];
console.log("Arreglo antes de ser ordenado:");
printArr(a);
seleccion(a);
console.log();
console.log("Arreglo despues de ser ordenado:");
printArr(a);
