#include <bits/stdc++.h>
using namespace std;

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int K, res = 0;
bool E[5][5]{};

void dfs(int r, int c, int l) {
    if (!(0 <= r && r < 5 && 0 <= c && c < 5) || E[r][c]) return;
    if (r == 4 && c == 4) {
        if (l == 5*5-K) ++res;
        return;
    }
    E[r][c] = true;
    for (auto& d: D) {
        dfs(r+d[0], c+d[1], l+1);
    }
    E[r][c] = false;
}

int main() {
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int r, c; cin >> r >> c; --r; --c;
        E[r][c] = true;
    }
    dfs(0, 0, 1);
    cout << res << endl;
}