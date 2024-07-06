#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int n) { p.assign(n, -1); }
    int size(int i) { return -p[find(i)]; }
    int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
    bool unite(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return 0;
        if (p[i] > p[j]) swap(i, j);
        p[i] += p[j];
        p[j] = i;
        return 1;
    }
};

const int MAXN = 2e5+5;
int N, Q;
vector<int> I[MAXN];
int A[MAXN], res[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int q = 0; q < Q; ++q) {
        int l, r; cin >> l >> r; --l, --r;
        I[r].push_back(q);
        res[q] = l;
    }
    stack<int> S;
    DSU dsu(N);
    for (int i = 0; i < N; ++i) {
        while (S.size() && A[S.top()] > A[i]) {
            dsu.unite(i, S.top());
            A[dsu.find(i)] = A[i];
            S.pop();
        }
        S.push(i);
        for (int q: I[i]) {
            int l = res[q];
            res[q] = A[dsu.find(l)];
        }
    }
    for (int q = 0; q < Q; ++q) cout << res[q] << endl;
}