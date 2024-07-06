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
    Node(Node<T>* n): a(n->a), b(n->b), l(n->l), r(n->r), val(n->val) {}
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
    Node<T>* update(int i, T x) {
        if (i+1 <= l || r <= i) return this;
        Node<T>* n = new Node<T>(this);
        if (i <= l && r <= i+1) {
            n->val = x;
            return n;
        }
        n->a = a->update(i, x), n->b = b->update(i, x);
        n->val = f(n->a->val, n->b->val);
        return n;
    }
};

int N, M;
vector<Node<ll>*> T;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    T.push_back(new Node<ll>(A, 0, N));
    while (M--) {
        int t, k; cin >> t >> k; --k;
        if (t == 3) {
            T.push_back(new Node<ll>(T[k]));
            continue;
        }
        if (t == 1) {
            int i, x; cin >> i >> x; --i;
            T[k] = T[k]->update(i, x);
            continue;
        }
        int l, r; cin >> l >> r; --l;
        cout << T[k]->query(l, r) << endl;
    }
}