#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int N, M;
vector<int> A[MAXN];
int V[MAXN];

int dfs(int i, int cur) {
    if (V[i]) {
        int res = cur-V[i]+1;
        if (res < 4) return 0;
        cout << res << endl;
        cout << i << ' ';
        return res;
    }
    V[i] = cur;
    for (int j: A[i]) {
        int res = dfs(j, cur+1);
        if (!res) continue;
        if (res > 1) {
            cout << i << ' ';
            --res;
        }
        return res;
    }
    V[i] = 1e9;
    return 0;
}

int main() {
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j;
        A[i].push_back(j);
        A[j].push_back(i);
    }
    bool res = 0;
    for (int i = 1; i <= N; ++i) {
        if (dfs(i, 1)) {
            res = 1;
            break;
        }
    }
    if (!res) cout << "IMPOSSIBLE" << endl;
}