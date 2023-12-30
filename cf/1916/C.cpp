#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define sz(x) ((int)(x).size())
#define ll long long
#define vr vector
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define ins insert
#define all(v) (v).begin(), (v).end()

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(v): i, find_by_order(i): v

const int d4r[4] = {0, 1, 0, -1}, d4c[4] = {1, 0, -1, 0};
const int d8r[8] = {0, -1, -1, -1, 0, 1, 1, 1}, d8c[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void fastio() {
    cin.tie(0), ios::sync_with_stdio(0);
}

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
    vr<int> p;
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

struct Tree {
    typedef int T;
    static constexpr T def = INT_MAX;
    T f(T a, T b) { return min(a, b); }
    vr<T> t; int n;
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

// struct BIT {
//     vr<ll> t;
//     BIT(int n): t(n) {}
//     void update(int i, int v) {
//         for (; i < sz(t); i |= i+1) t[i] += v;
//     }
//     ll query(int i) {
//         ll res = 0;
//         for (; i; i &= i-1) res += t[i-1];
//         return res;
//     }
// };

template<int...>
struct BIT {
    int v = 0;
    void update(int v) { this->v += v; }
    ll query() { return v; }
};

template<int N, int... Ns>
struct BIT<N, Ns...> {
    BIT<Ns...> bit[N];
    template<typename... Ts>
    void update(int i, Ts... args) {
        for (; i < N; i |= i+1) bit[i].update(args...);
    }
    template<typename... Ts>
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

// typedef pii fr;
// fr make_fr(int n, int d) {
//     if (d < 0) d = -d, n = -n;
//     return {n, d};
// }
// bool cmp(const fr& a, const fr& b) {
//     return (ll)a.f*b.s < (ll)b.f*a.s;
// }

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template<class K, class V> using umap = unordered_map<K, V, chash>;
template<class K> using uset = unordered_set<K, chash>;

int NT, N;

int sol(int a, int b) {
    if (a == 1) {
        return b ? 1 : 0;
    }
    int res = a/3 + (a%3 == 1);
    return res;
}

int main() {
    cin >> NT;
    while (NT--) {
        cin >> N;
        ll res = 0;
        int a = 0, b = 0;
        for (int i = 0; i < N; ++i) {
            int x; cin >> x;
            res += x;
            if (x%2 == 0) ++b;
            else ++a;
            cout << res-sol(a, b) << ' ';
        }
        cout << endl;
    }
}