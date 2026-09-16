function partition(a, l, h) {
    pvt = a[h];
    j = l - 1;
    for (k = l; k < h; k++) {
        if (a[k] < pvt) {
            j += 1
            swap(a, j, k);
        }
    }
    swap(a, j + 1, h);
    return j + 1;
}
function swap(a, j, k) {
    [a[j], a[k]] = [a[k], a[j]];
}
function qcksort(a, l, h) {
    if (l < h) {
        pi = partition(a, l, h);
        qcksort(a, l, pi - 1);
        qcksort(a, pi + 1, h);
    }
}
let a = [10, 7, 8, 9, 1, 5];
s = a.length;
console.log("El arreglo antes de ordenarlo:");
for (i = 0; i < s; i++) {
    process.stdout.write(a[i] + " ");
}
qcksort(a, 0, s - 1);
console.log();
console.log("El arreglo despues de ordenarlo:");
for (i = 0; i < s; i++) {
    process.stdout.write(a[i] + " ");
}