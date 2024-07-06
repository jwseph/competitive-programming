#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

struct Tree {
    typedef int T;
    static constexpr T def = 0;
    T f(T a, T b) { return a+b; }
    vector<T> t; int n;
    Tree(int n): t(2*n, def), n(n) {}
    void update(int i, T v) {
        for (t[i += n] = v; i /= 2;) t[i] = f(t[i*2], t[i*2+1]);
    }
    void add(int i, T v) {
        update(i, t[i+n] + v);
    }
    T query(int l, int r) {
        T al = def, ar = def;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l&1) al = f(al, t[l++]);
            if (r&1) ar = f(t[--r], ar);
        }
        return f(al, ar);
    }
};

const int MAXN = 2e5+5;
int N, M;
int A[MAXN];
vector<array<int, 3>> Q;
vector<int> C;
Tree T(0);

int lb(int a) {
    return lower_bound(all(C), a) - begin(C);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        C.push_back(A[i]);
    }
    for (int q = 0; q < M; ++q) {
        char t; int a, b; cin >> t >> a >> b;
        Q.push_back({t, a, b});
        if (t == '!') {
            C.push_back(b);
        }
    }
    sort(all(C));
    C.erase(unique(all(C)), end(C));
    T = Tree(C.size()+1);
    for (int i = 0; i < N; ++i) {
        T.add(lb(A[i]), 1);
    }
    for (auto [t, a, b]: Q) {
        if (t == '!') {
            int i = a-1;
            T.add(lb(A[i]), -1);
            A[i] = b;
            T.add(lb(A[i]), 1);
            continue;
        }
        cout << T.query(lb(a), lb(b+1)) << endl;
    }
}