#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define si set<int>
#define ui unordered_set<int>
#define mii map<int, int>
#define uii unordered_map<int, int>
#define uivi unordered_map<int, vi>
#define pii pair<int, int>
#define tiii tuple<int, int, int>

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
    return a%b == 0 ? b : gcd(b, a%b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

struct DSU {
    vector<int> p;
    DSU(int n) { p.assign(n, -1); }
    int size(int i) { return -p[find(i)]; }
    int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
    bool unite(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return 0;
        if (p[i] > p[j]) swap(i, j);
        p[i] += p[j];
        p[j] = i;
        return 1;
    }
};

ll fac[MAXX+1];
void factorial() {
    fac[0] = 1;
    for (int i = 1; i <= MAXX; ++i) fac[i] = fac[i-1] * i % MOD;
}

ll inv[MAXX+1];
void inverses() {
    inv[MAXX] = exp(fac[MAXX], MOD-2);
    for (int i = MAXX; i >= 1; --i) inv[i-1] = inv[i] * i % MOD;
}

int choose(int n, int k) {
    return fac[n] * inv[k] % MOD * inv[n-k] % MOD;
}

struct fr {
    int n, d;
    fr() { n = d = 0; }
    fr(int n, int d) {
        if (d < 0) d = -d, n = -n;
        this->n = n, this->d = d;
    }
    fr& operator=(fr f) { swap(*this, f); return *this; }
    friend void swap(fr& a, fr& b) { swap(a.n, b.n); swap(a.d, b.d); }
    friend ostream& operator<<(ostream& out, const fr& f) { return out << f.n << '/' << f.d; }
    friend bool operator<(const fr& a, const fr& b) { return (ll)a.n*b.d < (ll)b.n*a.d; }
    friend bool operator>(const fr& a, const fr& b) { return b < a; }
    friend bool operator<=(const fr& a, const fr& b) { return !(a > b); }
    friend bool operator>=(const fr& a, const fr& b) { return !(a < b); }
    friend bool operator==(const fr& a, const fr& b) { return a <= b && a >= b; }
};

// typedef pair<int, int> fr;
// fr make_fr(int n, int d) {
//     if (d < 0) d = -d, n = -n;
//     return {n, d};
// }
// bool cmp(const fr& a, const fr& b) {
//     return (ll)a.first*b.second < (ll)b.first*a.second;
// }