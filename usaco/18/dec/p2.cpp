#include <bits/stdc++.h>
using namespace std;

using pii = array<int, 2>;
using ll = long long;
const ll inf = 1e18+50;

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
    int mx; ll cnt;
    Node(): mx(0), cnt(0) {}
    Node(int mx, ll cnt): mx(mx), cnt(cnt) {}
    friend Node operator+(const Node& a, const Node& b) {
        return {
            max(a.mx, b.mx),
            a.mx > b.mx ? a.cnt : a.mx < b.mx ? b.cnt : min(a.cnt+b.cnt, inf)
        };
    }
};

const int N = 1e5+5;
int n; ll k;
int ar[N], skip[N];
Tree<Node> len(N);
vector<pii> idx[N];

int main() {
    ifstream cin("itout.in");
    ofstream cout("itout.out");
    cin >> n >> k; k--;
    len.update(N-1, Node(0, 1));
    for (int i = 0; i < n; ++i) cin >> ar[i];  // ar[i] > 0
    for (int i = n-1; i >= 0; --i) {
        Node q = len.query(ar[i]+1, N);
        len.update(ar[i], Node(q.mx+1, q.cnt));
        idx[q.mx+1].push_back({ar[i], i});
    }
    int p = 0;
    for (int s = n; s >= 1; --s) {
        sort(idx[s].begin(), idx[s].end(), greater<pii>());
        for (auto [a, i]: idx[s]) {
            if (p > i) continue;
            p = i;
            if (k >= len.query(a, a+1).cnt) {
                k -= len.query(a, a+1).cnt;
                continue;
            }
            skip[a] = 1;
            break;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) res += !skip[i];
    cout << res << endl;
    for (int i = 1; i <= n; ++i) {
        if (!skip[i]) cout << i << endl;
    }
}