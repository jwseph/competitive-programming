#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Tree {
    static constexpr T def{};
    T f(T a, T b) { return a+b; }
    vector<T> t; int n;
    Tree(int n): t(2*n, def), n(n) {}
    void inc(int l, int r, T v) {
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l&1) t[l++] += v;
            if (r&1) t[--r] += v;
        }
    }
    T query(int i) {
        T res = 0;
        for (res += t[i += n]; i /= 2;) res += t[i];
        return res;
    }
};

const int MAXN = 2e5+5;
int N, M;
int A[MAXN];
map<int, int> V;
vector<array<int, 2>> Q[MAXN];
int res[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    Tree<int> T(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int q = 0; q < M; ++q) {
        int l, r; cin >> l >> r; --l, --r;
        Q[r].push_back({l, q});
    }
    for (int i = 0; i < N; ++i) {
        T.inc(V[A[i]], i+1, 1);
        V[A[i]] = i+1;
        for (auto [l, q]: Q[i]) {
            res[q] = T.query(l);
        }
    }
    for (int q = 0; q < M; ++q) cout << res[q] << endl;
}