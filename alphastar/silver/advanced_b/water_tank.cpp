#include <bits/stdc++.h>
using namespace std;

#define MAXN 250

int N, M, A[MAXN], B[MAXN][2];
bool V[MAXN][MAXN]{};

int dfs(int b, int i) {
    if (b == M || V[b][i]) return INT_MAX;
    V[b][i] = 1;
    if (i == N-1) return b;
    int res = dfs(b+1, i);
    for (int j = i+1; j <= i+B[b][1] && j < N; ++j) {
        if (B[b][0] < A[i] || B[b][0] < A[j]) continue;
        res = min({res, dfs(b, j), dfs(b+1, j)});
    }
    return res;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int b = 0; b < M; ++b) cin >> B[b][0] >> B[b][1];
    cout << dfs(0, 0) << endl;
}