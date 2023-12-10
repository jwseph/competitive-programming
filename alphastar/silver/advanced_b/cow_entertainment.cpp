#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

#define MAXN 100005

int N, M, V[MAXN];
vector<pii> A[MAXN];

bool dfs(int i, int t) {
    if (V[i] >= 0) return V[i] == t;
    V[i] = t;
    bool res = 1;
    for (auto [j, w]: A[i]) {
        res &= dfs(j, (t+w)%2);
    }
    return res;
}

int main() {
    memset(V, -1, sizeof V);
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        char t; int i, j; cin >> t >> i >> j; --i; --j;
        A[i].push_back({j, t == 'D'});
        A[j].push_back({i, t == 'D'});
    }
    string res = "1";
    for (int i = 0; i < N; ++i) {
        if (V[i] >= 0) continue;
        res += '0';
        if (!dfs(i, 0)) {
            res = "0";
            break;
        }
    }
    cout << res << endl;
}