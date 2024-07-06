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

int n, m;
string s;
vector<int> idx;

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
    while (m--) {
        string t; cin >> t;
        cout << ub(t)-lb(t) << endl;
    }
}