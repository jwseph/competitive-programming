#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

#define MAXN 100005

int N, L[MAXN], R[MAXN];
pii A[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i].first >> A[i].second;
    sort(A, A+N);
    L[0] = INT_MAX;
    for (int i = 0; i < N; ++i) L[i+1] = min(L[i], A[i].second);
    R[N] = INT_MIN;
    for (int i = N-1; i >= 0; --i) R[i] = max(R[i+1], A[i].second);
    int res = 1;
    for (int i = 1; i < N; ++i) {
        // Connected iff L[i] <= R[i]
        res += L[i] > R[i];
    }
    cout << res << endl;
}