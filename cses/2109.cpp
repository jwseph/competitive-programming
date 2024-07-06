#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(v) begin(v), end(v)

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

struct SuffixArray {  // TODO: UPDATE TO USE willy108 VERS https://pastebin.com/JEAuS8a2
    string str; int n;
    vector<int> sa, isa;
    Tree<int> lcp;
    SuffixArray(string str_): str(str_+'$'), n(str.size()), sa(n), isa(n), lcp(n-1) {
        // sa has size sz(S)+1, starts with sz(S)
        iota(all(sa), 0);
        sort(all(sa), [&](int i, int j) { return str[i] < str[j]; });
        for (int i = 1; i < n; ++i) {
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
            for (int i = 1; i < n; ++i) {
                int l = sa[i-1], r = sa[i];
                isa[r] = is[l] == is[r] && is[l+k] == is[r+k] ? isa[l] : i;
            }
        }
        int k = 0;  // Kasai's Algo
        for (int r = 0; r < n-1; ++r) {
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

const int N = 1e5+5;
string s;
int n, stw = 0;
int lcp[N];
ll k, cnt[N];
stack<array<int, 2>> st;  // width, index

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> k; n = s.size(); --k;
    SuffixArray sa(s); sa.sa.erase(sa.sa.begin());
    for (int i = 1; i < n; ++i) lcp[i] = sa.getLCP(sa.sa[i], sa.sa[i-1]);
    for (int i = 0; i < n; ++i) {
        st.push({n-sa.sa[i]-stw, i});
        stw = n-sa.sa[i];
        int p = lcp[i+1];
        while (stw > p) {
            auto& [w, j] = st.top();
            int d = min(stw-p, w);
            cnt[j] += (ll)(i+1-j)*d;
            w -= d;
            stw -= d;
            if (!w) st.pop();
        }
    }
    for (int i = 0; i < n; ++i) {
        if (k >= cnt[i]) {
            k -= cnt[i];
            continue;
        }
        int x = lcp[i];
        int y = i;
        while (lcp[y+1] > x) {
            y++;
            lcp[y+1] = min(lcp[y+1], lcp[y]);
        }
        while (k >= y-i+1) {
            k -= y-i+1;
            x++;
            while (y > i && lcp[y] <= x) y--;
        }
        cout << s.substr(sa.sa[i], x+1) << endl;
        break;
    }
}