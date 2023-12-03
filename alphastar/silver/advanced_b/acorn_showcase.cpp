#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int N, M, X[MAXN], Y[MAXN], X1, X2, Y1, Y2;
vector<int> A[MAXN];
bool V[MAXN]{};

void dfs(int i) {
    if (V[i]) return;
    V[i] = 1;
    X1 = min(X1, X[i]);
    X2 = max(X2, X[i]);
    Y1 = min(Y1, Y[i]);
    Y2 = max(Y2, Y[i]);
    for (int j: A[i]) dfs(j);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j; --i; --j;
        A[i].push_back(j);
        A[j].push_back(i);
    }
    int res = INT_MAX;
    for (int i = 0; i < N; ++i) {
        if (V[i]) continue;
        X1 = X2 = X[i];
        Y1 = Y2 = Y[i];
        dfs(i);
        res = min(res, 2*(X2-X1+Y2-Y1));
    }
    cout << res << endl;
}