#include <bits/stdc++.h>
using namespace std;

#define MAXN 1'000'000

int N, M, A[MAXN];

int main() {
    cin >> N >> M;
    int t = 0;
    for (int i = 0; i < N; ++i) {
        int S, T; cin >> S >> T;
        while (T--) A[t++] = S;
    }
    t = 0;
    for (int i = 0; i < M; ++i) {
        int S, T; cin >> S >> T;
        while (T--) A[t++] -= S;
    }
    int cur = 0, p = 0, res = 0;
    for (int i = 0; i < t; ++i) {
        cur += A[i];
        if (cur < 0) {
            res += p > 0;
            p = -1;
        }
        if (cur > 0) {
            res += p < 0;
            p = 1;
        }
    }
    cout << res << endl;
}