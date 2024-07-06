#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

using H = array<int, 2>;
H operator+(H l, H r) {
	for (int i = 0; i < 2; ++i) if ((l[i] += r[i]) >= mod) l[i] -= mod;
	return l; }
H operator-(H l, H r) {
	for (int i = 0; i < 2; ++i) if ((l[i] -= r[i]) < 0) l[i] += mod;
	return l; }
H operator*(H l, H r) {
	for (int i = 0; i < 2; ++i) l[i] = (ll)l[i]*r[i]%mod;
	return l; }

mt19937 rng((random_device())());
uniform_int_distribution<int> bdist(.1*mod, .9*mod);  // not too close to ends
const H base{bdist(rng), bdist(rng)};
vector<H> pows{{1, 1}};
H power(int n) {
    while (n >= pows.size()) pows.push_back(pows.back()*base);
    return pows[n];
}

template<class T>
struct Tree {
    T def{};
    T f(T a, T b) { return a+b; }
    vector<T> t; int n;
    Tree(int n): t(2*n, def), n(n) {}
    void update(int i, T v) {
        for (t[i += n] = v; i /= 2;) t[i] = f(t[i*2], t[i*2+1]);
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
struct Node {
    int w; H h;
    Node(): w(0), h({}) {}
    Node(char c): w(1), h({c, c}) {}
    Node(int w, H h): w(w), h(h) {}
    friend Node operator+(const Node& a, const Node& b) {
        return {
            a.w+b.w,
            a.h*power(b.w)+b.h
        };
    }
};

int n, m;
string s;
Tree<Node> rk1(0), rk2(0);

void update(int i, char c) {
    rk1.update(i, c);
    rk2.update(n-1-i, c);
}

bool query(int l, int r) {
    return rk1.query(l, r).h == rk2.query(n-r, n-l).h;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s;
    rk1 = Tree<Node>(n), rk2 = Tree<Node>(n);
    for (int i = 0; i < n; ++i) update(i, s[i]);
    while (m--) {
        int t, i; cin >> t >> i; --i;
        if (t == 1) {
            char c; cin >> c;
            update(i, c);
            continue;
        }
        int j; cin >> j;
        cout << (query(i, j) ? "YES" : "NO") << endl;
    }
}