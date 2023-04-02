#include <bits/stdc++.h>
using namespace std;

#define MAXN 100'000

int N, A[MAXN], P[MAXN+1][3]{}, Q[3]{};

int max3(int S[3]) {
    return max({S[0], S[1], S[2]});
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        char C; cin >> C;
        A[i] = C == 'P' ? 0 : C == 'E' ? 1 : 2;
    }
    for (int i = N-1; i >= 0; --i) {
        for (int j = 0; j < 3; ++j) {
            P[i][j] = P[i+1][j];
        }
        ++P[i][A[i]];
    }
    int res = max3(P[0]);
    for (int i = 0; i < N; ++i) {
        ++Q[A[i]];
        res = max(res, max3(P[i+1])+max3(Q));
    }
    cout << res << endl;
}