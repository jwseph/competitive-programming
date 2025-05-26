#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+1;

struct Primes {
    int n, pr_n;
    int lp[10000007], pr[10000007];
    // vector<int> pr;
    Primes(int n1): n(n1) {
        lp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (!lp[i]) {
                lp[i] = i;
                pr[pr_n++] = i;
            }
            for (int j = 0; i*pr[j] <= n && pr[j] <= lp[i]; ++j) {
                lp[i*pr[j]] = pr[j];
            }
        }
    }
};

int nt, n;
Primes primes(N);
bitset<N> is_prime;

int main() {
    cin >> nt;
    for (int i = 1; i < N; ++i) {
        is_prime[i] = primes.lp[i] == i;
    }
    cout << primes.pr_n << endl;
    int res = 0;
    for (int i = 0; i < primes.pr_n; ++i) {
        int p = primes.pr[i];
        res += (is_prime>>p & is_prime).count() > 0;
    }
    cout << res << endl;
    // while (nt--) {
    //     cin >> n;
    //     // cout << Primes(n).pr.size() << endl;
    // }
}