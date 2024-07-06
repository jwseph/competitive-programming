#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int MAXN = 5e4+5;
int N, M;
vector<pii> A[MAXN], Q[MAXN];
set<pii> S[MAXN];
int res[MAXN];

int dfs(int i, int p = -1) {
    for (auto [j, e]: A[i]) {
        if (j == p) continue;
        res[e] = dfs(j, i);
        if (S[i].size() < S[j].size()) S[i].swap(S[j]);
        for (auto p: S[j]) {
            if (S[i].count(p)) S[i].erase(p);
            else S[i].insert(p);
        }
    }
    for (auto p: Q[i]) {
        if (S[i].count(p)) S[i].erase(p);
        else S[i].insert(p);
    }
    return S[i].size() ? S[i].begin()->first : -1;
}

int main() {
    ifstream cin("disrupt.in");
    ofstream cout("disrupt.out");
    cin >> N >> M;
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j;
        A[i].push_back({j, e}), A[j].push_back({i, e});
    }
    for (int e = 0; e < M; ++e) {
        int i, j, w; cin >> i >> j >> w;
        Q[i].push_back({w, e}), Q[j].push_back({w, e});
    }
    dfs(1);
    for (int e = 0; e < N-1; ++e) cout << res[e] << endl;
}