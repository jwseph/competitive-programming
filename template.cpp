#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define str string
#define vr vector
#define pii array<int, 2>
#define f first
#define s second
#define pb push_back
#define ins insert
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int d4r[4] = {0, 1, 0, -1}, d4c[4] = {1, 0, -1, 0};
const int d8r[8] = {0, -1, -1, -1, 0, 1, 1, 1}, d8c[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const array<int, 2> d4[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
const string D1 = "RULD", D2 = "LDRU";

// void dfs(int r, int c) {
//     if (r < 0 || r >= R || c < 0 || c >= C) return;
//     if (V[r][c]) return;
//     V[r][c] = 1;
//     for (auto [dr, dc]: d4) {
//         dfs(r+dr, c+dc);
//     }
// }

// void dfs(int i) {
//     if (V[i]) return;
//     V[i] = 1;
//     for (int j: A[i]) {
//         dfs(j);
//     }
// }

int exp(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = (ll)res*a % MOD;
        a = (ll)a*a % MOD;
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b) {
    return a == 0 ? b : gcd(b%a, a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int bit_length(ll x) {
    if (!x) return 0;
    return 64 - __builtin_clzll(x);
}

template<int...>
struct MBIT {
    int v = 0;
    void update(int v) { this->v += v; }
    ll query() { return v; }
};

template<int N, int... Ns>
struct MBIT<N, Ns...> {
    MBIT<Ns...> bit[N];
    template<class... Ts>
    void update(int i, Ts... args) {
        for (; i < N; i |= i+1) bit[i].update(args...);
    }
    template<class... Ts>
    ll query(int l, int r, Ts... args) {
        ll res = 0;
        for (; r; r &= r-1) res += bit[r-1].query(args...);
        for (; l; l &= l-1) res -= bit[l-1].query(args...);
        return res;
    }
};

// ll fac[MAXX+1];
// void factorial() {
//     fac[0] = 1;
//     for (int i = 1; i <= MAXX; ++i) fac[i] = fac[i-1] * i % MOD;
// }

// ll inv[MAXX+1];
// void inverses() {
//     inv[MAXX] = exp(fac[MAXX], MOD-2);
//     for (int i = MAXX; i >= 1; --i) inv[i-1] = inv[i] * i % MOD;
// }

// int choose(int n, int k) {
//     return fac[n] * inv[k] % MOD * inv[n-k] % MOD;
// }

vector<int> prefix(string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j && s[i] != s[j]) j = pi[j-1];
        j += s[i] == s[j];
        pi[i] = j;
    }
    return pi;
}

vector<int> zf(string& s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0, min(z[i-x], y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i+z[i]; z[i]++;
        }
    }
    return z;
}

template<class T>
struct MedianSet {
    using ll = long long;
    oset<pair<T, int>> S;
    map<T, int> cnt;
    pair<T, int> m;
    ll cost = 0; T median;
    void insert(T v) { insert({v, cnt[v]++}); }
    void insert(pair<T, int> p) {
        cost += abs(p.first-m.first);
        S.insert(p);
        update();
    }
    void erase(T v) { erase({v, --cnt[v]}); }
    void erase(pair<T, int> p) {
        cost -= abs(p.first-m.first);
        S.erase(p);
        update();
    }
    void update() {
        if (!size()) return;
        ll l = (size()-1)/2, r = size()-1-l;
        pair<T, int> n = *S.find_by_order(l);
        ll d = abs(m.first-n.first);
        cost += d * (n < m ? (r-(l+1)) : n > m ? (l-(r+1)) : 0);
        m = n, median = m.first;
    }
    int size() {
        return S.size();
    }
};