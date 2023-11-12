#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int N;
bool A[MAXN][MAXN];

void dfs(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N || !A[r][c]) return;
    A[r][c] = 0;
    dfs(r-1, c);
    dfs(r, c-1);
    dfs(r+1, c);
    dfs(r, c+1);
}

int main() {
    cin >> N;
    for (int r = 0; r < N; ++r) {
        string S; cin >> S;
        for (int c = 0; c < N; ++c) {
            A[r][c] = S[c] == '*';
        }
    }
    int res = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (!A[r][c]) continue;
            ++res;
            dfs(r, c);
        }
    }
    cout << res << endl;
}