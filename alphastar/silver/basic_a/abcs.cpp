#include <bits/stdc++.h>
using namespace std;

int N = 7, A[7];

int main() {
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A+N);
    int a = A[0], b = A[1], c = A[N-1]-a-b;
    cout << a << ' ' << b << ' ' << c << endl;
}