#include <bits/stdc++.h>
using namespace std;

#define N_MAX 25

int N, A[N_MAX][N_MAX];

int dfs(int r, int c) {
    if (r == N) return 0;
    return A[r][c] + max(dfs(r+1, c), dfs(r+1, c+1));
}

int main() {
    cin >> N;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c <= r; ++c) {
            cin >> A[r][c];
        }
    }
    cout << dfs(0, 0) << endl;
}