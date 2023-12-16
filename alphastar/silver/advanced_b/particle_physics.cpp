#include <bits/stdc++.h>
using namespace std;

#define MAXN 12

int N, W, H, X[MAXN], Y[MAXN], G[MAXN][MAXN];
vector<int> A, B;
bool V[MAXN]{}, V2[MAXN][MAXN];

bool dfs2(int x, int y, int dx, int dy) {
    if (x < 0 || x >= W || y < 0 || y >= H) return 0;
    if (V2[x][y]) return 1;
    V2[x][y] = 1;
    if (G[x][y] < 0) return dfs2(x+dx, y+dy, dx, dy);
    int i = G[x][y]/H, j = G[x][y]%H;
    return dfs2(i+dx, j+dy, dx, dy);
}

int dfs(int i) {
    if (i == N) {
        for (int x = 0; x < W; ++x) {
            for (int y = 0; y < H; ++y) {
                memset(V2, 0, sizeof V2);
                if (dfs2(x, y, 1, 0)) return 1;
            }
        }
        return 0;
    }
    if (V[i]) return dfs(i+1);
    int res = 0;
    for (int j = i+1; j < N; ++j) {
        if (V[j]) continue;
        V[i] = V[j] = 1;
        G[X[i]][Y[i]] = X[j]*H+Y[j];
        G[X[j]][Y[j]] = X[i]*H+Y[i];
        res += dfs(i+1);
        G[X[i]][Y[i]] = G[X[j]][Y[j]] = -1;
        V[i] = V[j] = 0;
    }
    return res;
}

int main() {
    memset(G, -1, sizeof G);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
        A.push_back(X[i]);
        B.push_back(Y[i]);
    }
    sort(begin(A), end(A)); A.erase(unique(begin(A), end(A)), end(A));
    sort(begin(B), end(B)); B.erase(unique(begin(B), end(B)), end(B));
    W = A.size(), H = B.size();
    for (int i = 0; i < N; ++i) {
        X[i] = lower_bound(begin(A), end(A), X[i]) - begin(A);
        Y[i] = lower_bound(begin(B), end(B), Y[i]) - begin(B);
    }
    cout << dfs(0) << endl;
}