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

int N, M;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    DSU dsu(N);
    int cnt = N, size = 1;
    while (M--) {
        int i, j; cin >> i >> j; --i; --j;
        cnt -= dsu.find(i) != dsu.find(j);
        dsu.unite(i, j);
        size = max(size, dsu.size(i));
        cout << cnt << ' ' << size << endl;
    }
}