#include <bits/stdc++.h>
using namespace std;

#define MAXN 100'000

int N, L[2*MAXN+1];
pair<int, char> A[MAXN+1];
stack<int> S;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A+N);
    int res = 0, j = 0;
    for (int i = 1; i < N; ++i) {
        if (A[i].second != A[j].second) j = i;
        if (i != j) res = max(res, A[i].first-A[j].first);
    }
    memset(L, -1, sizeof L);
    int P = 0;
    for (int i = 0; i <= N; ++i) {
        if (L[P+N] < 0) L[P+N] = i;
        else res = max(res, A[i-1].first-A[L[P+N]].first);
        P += A[i].second == 'S' ? 1 : -1;
    }
    cout << res << endl;
}