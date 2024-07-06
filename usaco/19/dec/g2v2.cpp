#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>; // i == order_of_key(v), v == *find_by_order(i)

struct HeavyLight {
    int N;
    vector<vector<int>> A;
    vector<int> P, D, sz, R;
    vector<unordered_map<int, oset<int>>> idx;
    HeavyLight(int N): N(N), A(N), P(N), D(N), sz(N), idx(N) {
        for (int i = 0; i < N; ++i) R.push_back(i);
    }
    void add(int i, int j) { A[i].push_back(j), A[j].push_back(i); }
    void dfs_sz(int i, int p = -1) {
        sz[i] = 1;
        for (int j: A[i]) {
            if (j == p) continue;
            P[j] = i, D[j] = D[i]+1;
            dfs_sz(j, i);
            sz[i] += sz[j];
        }
    }
    void dfs_hl(int i, int p = -1) {
        int k = -1;
        for (int& j: A[i]) {
            if (j == p) continue;
            if (k < 0 || sz[k] < sz[j]) {
                k = j;
                swap(j, A[i][0]);
            }
        }
        if (k >= 0) R[k] = R[i];
        for (int j: A[i]) {
            if (j == p) continue;
            dfs_hl(j, i);
        }
    }
    // For O(logn), don't support updates and instead add depths in order during dfs_hl
    void update(int i, int c) {  // O(log^2n)
        idx[R[i]][c].insert(D[i]);
    }
    int query(int i, int j, int c) {  // O(log^2n)
        int res = 0;
        while (R[i] != R[j]) {
            if (D[R[i]] < D[R[j]]) swap(i, j);
            res += idx[R[i]][c].order_of_key(D[i]+1);  // For O(logn), only compare the minimum here
            i = P[R[i]];
        }
        if (D[i] < D[j]) swap(i, j);
        res += idx[R[i]][c].order_of_key(D[i]+1) - idx[R[i]][c].order_of_key(D[j]);  // No need to compare the minimum here because this is only called once per query
        return res;
    }
};

const int MAXN = 1e5+5;
int N, M;
int C[MAXN];

int main() {
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> C[i];
    HeavyLight G(N);
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j; --i, --j;
        G.add(i, j);
    }
    G.dfs_sz(0), G.dfs_hl(0);
    for (int i = 0; i < N; ++i) {
        G.update(i, C[i]);
    }
    while (M--) {
        int i, j, c; cin >> i >> j >> c; --i, --j;
        cout << !!G.query(i, j, c);
    }
    cout << endl;
}