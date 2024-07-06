#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = array<int, 2>;

struct Primes {
    int n;
    vector<int> primes, lp, phi;
    Primes(int n): n(n), lp(n+1), phi(n+1) {
        lp[1] = phi[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (!lp[i]) {
                lp[i] = i;
                primes.push_back(i);
                phi[i] = i-1;
            }
            for (int p: primes) {
                if (i*p > n) break;
                lp[i*p] = p;
                if (lp[i] == p) {
                    phi[i*p] = phi[i]*p;
                }
                phi[i*p] = phi[i]*phi[p];
            }
        }
    }
    vector<pii> fzn(int x) {
        vector<pii> res;
        while (x > 1) {
            int p = lp[x], k = 0;
            while (x%p == 0) ++k, x /= p;
            res.push_back({p, k});
        }
        return res;
    }
};

const int N = 1e5+5, M = 1e6+5;
int n;
Primes pr(1e6+5);
int cnt[M];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    ll res = 0;
    while (n--) {
        int a; cin >> a;
        auto pf = pr.fzn(a);
        for (int s = 0; s < 1<<pf.size(); ++s) {
            int p = 1, c = 1;
            for (int i = 0; i < pf.size(); ++i) {
                if (s&1<<i) p *= pf[i][0], c *= -1;
            }
            res += c*cnt[p]++;
        }
    }
    cout << res << endl;
}