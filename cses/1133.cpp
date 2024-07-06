#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2e5+5;
int N;
vector<int> A[MAXN];
int SZ[MAXN];
ll R[MAXN];

ll dfs1(int i, int p) {
    ll res = 0;
    SZ[i] = 1;
    for (int j: A[i]) {
        if (j == p) continue;
        res += dfs1(j, i) + SZ[j];
        SZ[i] += SZ[j];
    }
    return res;
}

int dfs2(int i, int p, ll cur) {
    R[i] = cur;
    int res = 0;
    for (int j: A[i]) {
        if (j == p) continue;
        res += dfs2(j, i, cur+N-2*SZ[j]);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j; --i, --j;
        A[i].push_back(j), A[j].push_back(i);
    }
    ll tot = dfs1(0, -1);
    dfs2(0, -1, tot);
    for (int i = 0; i < N; ++i) cout << R[i] << ' ';
    cout << endl;
}