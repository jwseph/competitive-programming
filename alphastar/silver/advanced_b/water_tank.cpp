#include <bits/stdc++.h>
using namespace std;

#define MAXN 251
#define tiii tuple<int, int, int>

int N, M, A[MAXN], B[MAXN][2];
bool V[MAXN][MAXN]{};
priority_queue<tiii, vector<tiii>, greater<>> Q;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int b = 0; b < M; ++b) cin >> B[b][0] >> B[b][1];
    Q.push({0, 0, 0});
    while (Q.size()) {
        auto [w, b, i] = Q.top();
        Q.pop();
        if (i == N-1) {
            cout << b << endl;
            return 0;
        }
        if (V[b][i]) continue;
        V[b][i] = 1;
        if (b == M) continue;
        Q.push({w+1, b+1, i});
        for (int j = i+1; j <= i+B[b][1] && j < N; ++j) {
            if (B[b][0] < A[i] || B[b][0] < A[j] || V[b+1][j]) continue;
            Q.push({w, b, j});
            Q.push({w, b+1, j});
        }
    }
    cout << "impossible" << endl;
}