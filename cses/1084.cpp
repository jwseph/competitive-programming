#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int N, M, K, A[MAXN], B[MAXN];

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) cin >> B[i];
    sort(A, A+N);
    sort(B, B+M);
    int res = 0;
    for (int i = 0, j = 0; i < N; ++i) {
        while (j < M && B[j] < A[i]-K) ++j;
        if (j == M || B[j] > A[i]+K) continue;
        ++res;
        ++j;
    }
    cout << res << endl;
}