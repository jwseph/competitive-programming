#include <bits/stdc++.h>
using namespace std;

int K;
bool V[5][5]{};

int dfs(int r, int c) {
    if (!(0 <= r && r < 5 && 0 <= c && c < 5) || V[r][c]) {
        return 0;
    }
    if (r == 4 && c == 4) {
        return K == 25-1;
    }
    V[r][c] = true; ++K;
    int res = dfs(r-1, c)+dfs(r+1, c)+dfs(r, c-1)+dfs(r, c+1);
    V[r][c] = false; --K;
    return res;
}

int main() {
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int r, c; cin >> r >> c; --r; --c;
        V[r][c] = true;
    }
    cout << dfs(0, 0) << endl;
}