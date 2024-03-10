#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int N, M;
vector<int> A[MAXN];
int C[MAXN];

bool dfs(int i, int c) {
    if (C[i]) return C[i] == c;
    C[i] = c;
    bool res = 1;
    for (int j: A[i]) {
        res &= dfs(j, 3-c);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j;
        A[i].push_back(j);
        A[j].push_back(i);
    }
    bool res = 1;
    for (int i = 1; i <= N && res; ++i) {
        if (C[i]) continue;
        res &= dfs(i, 1);
    }
    if (!res) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 1; i <= N; ++i) {
        cout << C[i] << ' ';
    }
    cout << endl;
}