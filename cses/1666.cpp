#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int N, M;
vector<int> A[MAXN], G;
bool V[MAXN];

void dfs(int i) {
    if (V[i]) return;
    V[i] = 1;
    for (int j: A[i]) {
        dfs(j);
    }
}

int main() {
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j; --i; --j;
        A[i].push_back(j);
        A[j].push_back(i);
    }
    for (int i = 0; i < N; ++i) {
        if (V[i]) continue;
        G.push_back(i);
        dfs(i);
    }
    int res = G.size()-1;
    cout << res << endl;
    for (int i = 0; i < res; ++i) {
        cout << G[i]+1 << ' ' << G[res]+1 << endl;
    }
}