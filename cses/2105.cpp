#include <bits/stdc++.h>
using namespace std;

#define all(v) begin(v), end(v)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
using ll = long long;

template<class T>
struct Tree {
    static constexpr T def = INT_MAX;
    T f(T a, T b) { return min(a, b); }
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

struct SuffixArray {
    string str; int n;
    vector<int> sa, isa;
    Tree<int> lcp;
    SuffixArray(string str): str(str+'$'), n(str.size()+1), sa(n), isa(n), lcp(n-1) {
        // sa has size sz(S)+1, starts with sz(S)
        iota(all(sa), 0);
        sort(all(sa), [&](int i, int j) { return str[i] < str[j]; });
        FOR(i, 1, n) {
            int l = sa[i-1], r = sa[i];
            isa[r] = i > 1 && str[l] == str[r] ? isa[l] : i;
        }
        for (int k = 1; k < n; k *= 2) {
            // currently sorted by first k chars
            vector<int> s(sa), is(isa), pos(n);
            iota(all(pos), 0);
            for (int t: s) {
                int T = t-k;  // verify that nothing goes out of bounds
                if (T >= 0) sa[pos[isa[T]]++] = T;
            }
            FOR(i, 1, n) {
                int l = sa[i-1], r = sa[i];
                isa[r] = is[l] == is[r] && is[l+k] == is[r+k] ? isa[l] : i;
            }
        }
        int k = 0;  // Kasai's Algo
        FOR(r, 0, n-1) {
            int l = sa[isa[r]-1];
            while (l+k < n-1 && str[l+k] == str[r+k]) ++k;
            lcp.update(isa[r]-1, k);
            if (k) k--;
        }
		// if we cut off first chars of two strings
		// with lcp k then remaining portions still have lcp k-1
    }
    int getLCP(int i, int j) {
        if (i == j) return n-1-i;
        int l = isa[i], r = isa[j];
        if (l > r) swap(l, r);
        return lcp.query(l, r);
    }
};

string s;
int n;

int main() {
    cin >> s; n = s.size();
    SuffixArray sa(s);
    ll res = (ll)n*(n+1)/2;
    FOR(p, 1, n) res -= sa.getLCP(sa.sa[p], sa.sa[p+1]);
    cout << res << endl;
}