#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, b, a) for (int i = (b)-1; i >= (a); --i)

vector<int> sort_cyclic_shifts(const string& s) {
    int n = s.size(), m = 256;
    vector<int> p(n), c(n), cnt(max(m, n));
    FOR(i, 0, n) cnt[s[i]]++;
    FOR(a, 1, m) cnt[a] += cnt[a-1];
    ROF(i, n, 0) p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    FOR(i, 1, n) {
        classes += s[p[i]] != s[p[i-1]];
        c[p[i]] = classes-1;
    }

    vector<int> pl(n), cl(n);
    for (int w = 1; w < n; w *= 2) {
        FOR(i, 0, n) pl[i] = (p[i]-w+n) % n;
        fill(begin(cnt), begin(cnt)+classes, 0);
        FOR(i, 0, n) cnt[c[pl[i]]]++;
        FOR(a, 1, classes) cnt[a] += cnt[a-1];
        ROF(i, n, 0) p[--cnt[c[pl[i]]]] = pl[i];
        cl[p[0]] = 0;
        classes = 1;
        FOR(i, 1, n) {
            classes += c[p[i]] != c[p[i-1]] || c[(p[i]+w)%n] != c[(p[i-1]+w)%n];
            cl[p[i]] = classes-1;
        }
        c.swap(cl);
    }
    return p;
}

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

const int N = 1e5+5;
int n, m;
string s;
vector<int> idx;
Tree<int> tr(N);

int lb(const string& t) {
    int l = 0, r = n, tn = t.size();
    while (l < r) {
        int h = (l+r)/2;
        if (t <= s.substr(idx[h], min(tn, n-idx[h]))) r = h;
        else l = h+1;
    }
    return l;
}

int ub(const string& t) {
    int l = 0, r = n, tn = t.size();
    while (l < r) {
        int h = (l+r)/2;
        if (t < s.substr(idx[h], min(tn, n-idx[h]))) r = h;
        else l = h+1;
    }
    return l;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> m;
    n = s.size();
    idx = sort_cyclic_shifts(s+'$');
    idx.erase(begin(idx));
    for (int i = 0; i < n; ++i) tr.update(i, idx[i]);
    while (m--) {
        string t; cin >> t;
        int res = tr.query(lb(t), ub(t));
        cout << (res < INT_MAX ? res+1 : -1) << endl;
    }
}