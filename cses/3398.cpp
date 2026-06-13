#include <bits/stdc++.h>
using namespace std;

using arr2 = array<int, 2>;
using ll = long long;

struct Primes {
    int n;
    vector<int> primes, lp;
    Primes(int n): n(n), lp(n+1) {
        lp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (!lp[i]) {
                lp[i] = i;
                primes.push_back(i);
            }
            for (int p: primes) {
                if (i*p > n) break;
                lp[i*p] = p;
            }
        }
    }
    vector<arr2> fzn(int x) {
        vector<arr2> res;
        while (x > 1) {
            int p = lp[x], k = 0;
            while (x%p == 0) ++k, x /= p;
            res.push_back({p, k});
        }
        return res;
    }
};

const int N = 2e5+5;

int n, a[N], v[N], cnt[N];

int main() {
    cin >> n;
    Primes P(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i0 = 1; i0 <= n; ++i0) {
        int i = i0, len = 0;
        while (!v[i]) {
            v[i] = 1;
            i = a[i];
            len++;
        }
        for (auto [p, k]: P.fzn(len)) {
            cnt[p] = max(cnt[p], k);
        }
    }
    ll res = 1, mod = 1e9+7;
    for (int p: P.primes) {
        while (cnt[p]--) {
            res *= p;
            res %= mod;
        }
    }
    cout << res << endl;
}