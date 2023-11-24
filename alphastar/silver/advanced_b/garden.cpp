#include <bits/stdc++.h>
using namespace std;

#define MAXN 18

int N;
string A[MAXN], S;
unordered_set<string> U[MAXN], V[MAXN], res;

void dfs(int r, int c, unordered_set<string>* W) {
    if (r < 0 || r >= N || c < 0 || c >= N) return;
    S += A[r][c];
    if (S.size() == N) {
        W[r].insert(S);
    } else {
        dfs(r+1, c, W);
        dfs(r, c+1, W);
    }
    S.pop_back();
}

int main() {
    // 2^17
    cin >> N;
    for (int r = 0; r < N; ++r) {
        cin >> A[r];
    }
    dfs(0, 0, U);
    for (int r = 0; r < N; ++r) {
        reverse(begin(A[r]), end(A[r]));
    }
    reverse(A, A+N);
    dfs(0, 0, V);
    for (int r = 0; r < N; ++r) {
        for (const string& s: U[r]) {
            if (V[N-1-r].find(s) == V[N-1-r].end()) continue;
            res.insert(s);
        }
    }
    cout << res.size() << endl;
}