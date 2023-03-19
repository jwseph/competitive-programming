#include <bits/stdc++.h>
using namespace std;

#define N_MAX 50'000

int N, A[N_MAX];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A+N);
    int i, j = 1, k = 0;
    for (i = 0; i < N; ++i) {
        while (j <= 2*N && (j <= A[k] || j < A[i])) {
            ++j;
            if (k < N && j == A[k+1]) ++k;
        }
        if (j > 2*N) break;
        ++j;
        if (k < N && j == A[k+1]) ++k;
    }
    cout << i << endl;
}