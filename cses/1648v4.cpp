#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct Node {
    static constexpr T def{};
    T f(T a, T b) { return a+b; }
    Node *a, *b;
    int l, r;
    T val = def;
    Node(int l, int r): l(l), r(r) {}
    Node(vector<int>& v, int l, int r): l(l), r(r) {
        if (l+1 >= r) {
            val = v[l];
            return;
        }
        int h = (l+r)/2;
        a = new Node<T>(v, l, h), b = new Node<T>(v, h, r);
        val = f(a->val, b->val);
    }
    T query(int L, int R) {
        if (R <= l || r <= L) return def;
        if (L <= l && r <= R) return val;
        return f(a->query(L, R), b->query(L, R));
    }
    void update(int i, T x) {
        if (i < l || r <= i) return;
        if (i <= l && r <= i+1) {
            val = x;
            return;
        }
        a->update(i, x), b->update(i, x);
        val = f(a->val, b->val);
    }
};

int N, M;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    Node<ll> T(A, 0, N);
    while (M--) {
        int t; cin >> t;
        if (t == 1) {
            int i, a; cin >> i >> a; --i;
            T.update(i, a);
            continue;
        }
        int l, r; cin >> l >> r; --l;
        cout << T.query(l, r) << endl;
    }
}