#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using arr2 = array<ll, 2>;

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
    vector<arr2> fzn(ll x) {
        if (x > (ll)n*n) {
            cout << "range error" << endl;
        }
        vector<arr2> res;
        for (ll p: primes) {
            if (p*p > x || x <= n) break;
            if (x%p == 0) {
                int k = 0;
                while (x%p == 0) x /= p, k++;
                res.push_back({p, k});
            }
        }
        while (1 < x && x <= n) {
            int p = lp[x], k = 0;
            while (x%p == 0) x /= p, k++;
            res.push_back({p, k});
        }
        if (x > n && x > 1) {
            res.push_back({x, 1});
        }
        return res;
    }
};

Primes P(3000006);

bool is1(ll n) {
    ll rt = sqrtl(n*8+1);
    return rt*rt == n*8+1;
}

bool is2(ll n) {
    // check if 8n+2 is sum of squares
    // forall pf of 8n+2, if p%4 == 3, then k%2 == 0
    for (auto [p, k]: P.fzn(n*8+2)) {
        if (p%4 == 3 && k%2 != 0) return false;
    }
    return true;
}

int main() {
    int nt; cin >> nt;
    while (nt--) {
        ll n; cin >> n;
        if (is1(n)) {
            cout << 1 << endl;
            continue;
        }
        if (is2(n)) {
            cout << 2 << endl;
            continue;
        }
        cout << 3 << endl;
    }
}