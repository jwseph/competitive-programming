#include <bits/stdc++.h>
using namespace std;

#define S_MAX 102

int N, R = S_MAX, C = S_MAX, res = 0;
bool A[S_MAX][S_MAX]{}, V[S_MAX][S_MAX]{};

void dfs(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C || V[r][c]) return;
    if (A[r][c]) {
        ++res;
        return;
    }
    V[r][c] = true;
    dfs(r-1, c);
    dfs(r+1, c);
    dfs(r, c-1);
    dfs(r, c+1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int r, c; cin >> c >> r;
        A[r][c] = true;
    }
    dfs(0, 0);
    cout << res << endl;
}