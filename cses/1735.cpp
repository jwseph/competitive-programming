#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct Node {
    static constexpr T def{}, unset = LLONG_MIN;
    T f(T a, T b) { return a+b; }
    Node *a, *b;
    int l, r;
    T val = def, mset = unset, madd = def;
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
        push();
        return f(a->query(L, R), b->query(L, R));
    }
    void set(int L, int R, T x) {
        if (R <= l || r <= L) return;
        if (L <= l && r <= R) {  // OVERRIDE
            mset = x, madd = 0;
            val = (r-l)*x;
            return;
        }
        push();
        a->set(L, R, x), b->set(L, R, x);
        val = f(a->val, b->val);
    }
    void add(int L, int R, T x) {
        if (R <= l || r <= L) return;
        if (L <= l && r <= R) {  // OVERRIDE
            (mset == unset ? madd : mset) += x;
            val += (r-l)*x;
            return;
        }
        push();
        a->add(L, R, x), b->add(L, R, x);
        val = f(a->val, b->val);
    }
    void push() {
        if (!a) {
            int h = (l+r)/2;
            a = new Node<T>(l, h), b = new Node<T>(h, r);
        }
        if (mset != unset) {
            a->set(l, r, mset), b->set(l, r, mset), mset = unset;
        } else if (madd) {
            a->add(l, r, madd), b->add(l, r, madd), madd = 0;
        }
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
        int t, l, r; cin >> t >> l >> r; --l;
        if (t == 3) {
            cout << T.query(l, r) << endl;
            continue;
        }
        int x; cin >> x;
        if (t == 1) {
            T.add(l, r, x);
            continue;
        }
        T.set(l, r, x);
    }
}