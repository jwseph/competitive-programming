#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int V[N][N], v = 0;
int A[N][N];

int dr[8] = {-2, 2, -1, 1, -1, 1, -2, 2};
int dc[8] = {-1, -1, -2, -2, 2, 2, 1, 1};

bool sol(int r, int c, int t) {
    if (V[r][c]) return 0;
    V[r][c] = t;
    ++v;
    if (v == N*N) return 1;
    vector<array<int, 3>> adj;
    for (int d = 0; d < 8; ++d) {
        int i = r+dr[d], j = c+dc[d];
        if (i < 0 || i >= N || j < 0 || j >= N || V[i][j]) continue;
        adj.push_back({--A[i][j], i, j});
    }
    sort(begin(adj), end(adj));
    for (auto [a, i, j]: adj) {
        if (sol(i, j, t+1)) return 1;
    }
    for (auto [a, i, j]: adj) ++A[i][j];
    V[r][c] = 0;
    --v;
    return 0;
}

int main() {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            for (int d = 0; d < 8; ++d) {
                int i = r+dr[d], j = c+dc[d];
                if (i < 0 || i >= N || j < 0 || j >= N) continue;
                ++A[r][c];
            }
        }
    }
    int i, j; cin >> j >> i; --i, --j;
    sol(i, j, 1);
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cout << V[r][c] << ' ';
        }
        cout << endl;
    }
}