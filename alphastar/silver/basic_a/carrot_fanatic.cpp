#include <bits/stdc++.h>
using namespace std;

#define N_MAX 50'000

int N, K, A[N_MAX], P[N_MAX];

int main() {
    cin >> N >> K;
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A+N);
    for (int i = 0; i < N; ++i) {
        P[i] = upper_bound(A, A+N, A[i]+K)-A - i;
    }
    for (int i = N-2; i >= 0; --i) {
        P[i] = max(P[i], P[i+1]);
    }
    int res = 1;
    for (int i = 1; i < N; ++i) {
        int j = lower_bound(A, A+N, A[i-1]-K)-A;
        int cur = i-j + P[i];
        res = max(res, cur);
    }
    cout << res << endl;
}