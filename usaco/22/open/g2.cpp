#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<bool> simplify(string S) {
    vector<bool> res;
    for (char c: S) {
        if (c == '1') continue;
        if (c == '0') res = {};
        res.push_back(c == '+');
    }
    return res;
}

int NT, N, M;
vector<bool> A, B;
vector<vector<vector<int>>> dp;

int sol(int i, int j, int p) {
    if (i > N || j > M) return 0;
    if (i == N && j == M) return 1;
    if (dp[i][j][p] >= 0) return dp[i][j][p];
    int res = 0;
    if (i < N) res += sol(i+1, j, 0);
    res %= MOD;
    if (j < M && !(p == 0 && A[i-1] == B[j])) res += sol(i, j+1, 1);
    res %= MOD;
    return dp[i][j][p] = res;
}

int main() {
    cin >> NT;
    while (NT--) {
        cin >> N;
        string S, T; cin >> S >> T;
        A = simplify(S); N = A.size();
        B = simplify(T); M = B.size();
        dp.assign(N+1, vector<vector<int>>(M+1, vector<int>(2, -1)));
        cout << sol(0, 0, 1) << endl;
    }
}