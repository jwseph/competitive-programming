var N = 100;
var A = [];
for (var i = 0; i <= N; i++) {
    A.push(0);
}
A[0] = 1;
for (var k = 1; k <= N; k++) {
    for (var i = k; i <= N; i++) {
        A[i] += A[i-k];
    }
}
console.log(A[N]-1);