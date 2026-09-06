let x = 0, y = 0, r = 3, k = 0;
let arr = [9];
let arr2 = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];
for (x = 0; x < r; x++) {
    for (y = 0; y < r; y++) {
        arr[k] = arr2[x][y];
        k++;
    }
}
console.log("Los elementos del array bidimensional son: ");
for (x = 0; x < r; x++) {
    for (y = 0; y < r; y++) {
        process.stdout.write(arr2[x][y] + " "); //EL + " " CONVIERTE EL NUMERO A TEXTO PORQUE LA SUMA EN JAVASCRIPT HACE ESO
    }
    console.log();
}
console.log("Los elementos del array unidimensional son: ");
for (y = 0; y < r; y++) {
    for (x = 0; x < r; x++) {
        process.stdout.write(arr[x * r + y] + " ");
    }
}

