#include <bits/stdc++.h>
using namespace std;

#define MAXN 30'001

int N, A[MAXN], P[MAXN], Q[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    P[0] = 0;
    for (int i = 1; i <= N; ++i) {
        P[i] = P[i-1] + (A[i-1] == 2);
    }
    Q[N] = 0;
    for (int i = N-1; i >= 0; --i) {
        Q[i] = Q[i+1] + (A[i] == 1);
    }
    int res = INT_MAX;
    for (int i = 0; i <= N; ++i) {
        res = min(res, P[i]+Q[i]);
    }
    cout << res << endl;
}