#include <bits/stdc++.h>
using namespace std;

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
    bool is_prime(ll x) {
        if (x <= primes.back()) {
            return binary_search(begin(primes), end(primes), x);
        }
        for (ll p: primes) {
            if (p*p > x) break;
            if (x%p == 0) return false;
        }
        return true;
    }
};

Primes P(1000006);

bool is_prime(ll x) {
    if (x <= P.primes.back()) {
        return binary_search(begin(P.primes), end(P.primes), x);
    }
    for (ll p: P.primes) {
        if (p*p > x) break;
        if (x%p == 0) return false;
    }
    return true;
}

int main() {
    int nt; cin >> nt;
    while (nt--) {
        ll x; cin >> x;
        ++x;
        while (!is_prime(x)) ++x;
        cout << x << endl;
    }
}