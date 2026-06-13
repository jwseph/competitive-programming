#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int n = 7;
int v[n][n];
int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
int req[n*n-1];

ll num_calls = 0;

int dfs(int r, int c, int step = 0) {
    num_calls++;
    if (r == n-1 && c == 0) return step == n*n-1;
    int res = 0;
    for (int d = 0; d < 4; ++d) {
        if (req[step] != -1 && req[step] != d) continue;

        int i = r+dr[d], j = c+dc[d];
        if (i < 0 || i >= n || j < 0 || j >= n) continue;
        if (v[i][j]) continue;

        // check hits a wall
        int fi = i+dr[d], fj = j+dc[d];
        int li = i-dc[d], lj = j+dr[d];
        int ri = i+dc[d], rj = j-dr[d];
        bool fwall = fi < 0 || fi >= n || fj < 0 || fj >= n || v[fi][fj];
        bool lempty = li >= 0 && li < n && lj >= 0 && lj < n && !v[li][lj];
        bool rempty = ri >= 0 && ri < n && rj >= 0 && rj < n && !v[ri][rj];
        if (fwall && lempty && rempty) continue;

        v[i][j] = 1;
        res += dfs(i, j, step+1);
        v[i][j] = 0;
    }
    return res;
}

int main() {
    string s; cin >> s;
    for (int i = 0; i < n*n-1; ++i) {
        switch (s[i]) {
            case 'R': req[i] = 0; break;
            case 'D': req[i] = 1; break;
            case 'L': req[i] = 2; break;
            case 'U': req[i] = 3; break;
            case '?': req[i] = -1; break;
        }
    }
    v[0][0] = 1;
    clock_t start = clock();
    int res = dfs(0, 0);
    clock_t end = clock();
    cout << res << endl;
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    // cerr << "Elapsed time: " << elapsed << " seconds" << endl;
    // cerr << "Number of calls: " << num_calls << endl;
}