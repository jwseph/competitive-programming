#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int N;
string A[MAXN][MAXN];
int dr[6] = {-1, 1, 0, 0, 0, 0};
int dc[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

void dfs(int r, int c, int z) {
    if (r < 0 || r >= N || c < 0 || c >= N || z < 0 || z >= N || A[r][c][z] == '.') return;
    A[r][c][z] = '.';
    for (int d = 0; d < 6; ++d) {
        int i = r+dr[d], j = c+dc[d], k = z+dz[d];
        dfs(i, j, k);
    }
}

int main() {
    cin >> N;
    for (int z = 0; z < N; ++z) {
        for (int r = 0; r < N; ++r) {
            cin >> A[r][z];
        }
    }
    int res = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            for (int z = 0; z < N; ++z) {
                if (A[r][c][z] == '.') continue;
                dfs(r, c, z);
                ++res;
            }
        }
    }
    cout << res << endl;
}