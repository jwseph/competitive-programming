#include <bits/stdc++.h>
using namespace std;

#define MAXN 50'000

int N, K, A[MAXN], P[MAXN+1];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A+N);
    P[MAXN] = 0;
    for (int i = N-1; i >= 0; --i) {
        int cur = upper_bound(A, A+N, A[i]+K)-A-i;
        P[i] = max(P[i+1], cur);
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        int cur = i+1-(lower_bound(A, A+N, A[i]-K)-A) + P[i+1];
        res = max(res, cur);
    }
    cout << res << endl;
}