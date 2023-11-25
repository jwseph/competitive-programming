#include <bits/stdc++.h>
using namespace std;

#define MAXN 30

int R, C, K, A[MAXN][MAXN];
bool V[MAXN][MAXN]{};
vector<pair<int, int>> cur, res;

void splash(int r, int c, int e) {
    for (int i = r-1; i <= r+1; ++i) {
        for (int j = c-1; j <= c+1; ++j) {
            if (i < 0 || i >= R || j < 0 || j >= C) continue;
            A[i][j] += e;
        }
    }
}

bool dfs(int r, int c, int k) {
    if (k < 0) return 0;
    if (c == C) return dfs(r+1, 0, k);
    if (r == R) {
        if (k == 0) {
            auto tmp = cur;
            sort(begin(tmp), end(tmp));
            res = res.size() ? min(res, tmp) : tmp;
        }
        return 0;
    }
    if (A[r][c] < 0) return 0;
    vector<pair<int, int>> slots;
    for (int i = r-1; i <= r+1; ++i) {
        for (int j = c-1; j <= c+1; ++j) {
            if (i < 0 || i >= R || j < 0 || j >= C || V[i][j]) continue;
            slots.push_back({i, j});
        }
    }
    for (auto [i, j]: slots) V[i][j] = 1;
    for (int s = 0; s < (1<<slots.size()); ++s) {
        for (int si = 0; si < slots.size(); ++si) {
            if (s&1<<si) continue;
            auto [i, j] = slots[si];
            splash(i, j, -1);
            cur.push_back({i+1, j+1});
            --k;
        }
        if (A[r][c] == 0) {
            dfs(r, c+1, k);
        }
        for (int si = 0; si < slots.size(); ++si) {
            if (s&1<<si) continue;
            auto [i, j] = slots[si];
            splash(i, j, 1);
            cur.pop_back();
            ++k;
        }
    }
    for (auto [i, j]: slots) V[i][j] = 0;
    return 0;
}

int main() {
    cin >> R >> C >> K;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> A[r][c];
        }
    }
    dfs(0, 0, K);
    if (!res.size()) cout << "NO SOLUTION" << endl;
    for (auto [r, c]: res) cout << r << ' ' << c << endl;
}