#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e7+1;

int nt, n;
bitset<N> is_prime, is_prime2;
int primes[1000000], primes_n = 0;

int main() {
    // is_prime = ~is_prime;
    for (int i = 0; i < N; ++i) is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < N; ++i) {
        if (!is_prime[i] || (ll)i*i >= N) continue;
        for (int j = i*i; j < N; j += i) {
            is_prime[j] = 0;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (is_prime[i]) primes[primes_n++] = i;
    }
    cout << primes_n << endl;

    cin >> nt;
    for (int t = 1; t <= nt; ++t) {
        cin >> n;
        is_prime2 = is_prime;
        for (int i = n+1; i < N; ++i) is_prime2[i] = 0;
        int res = 0;
        for (int j = 0; j < primes_n && primes[j] <= n; ++j) {
            bitset<N> tmp = is_prime2;
            tmp >>= primes[j];
            tmp &= is_prime2;
            if (tmp.count()) {
                res++;
            }
        }
        cout << "Case #" << t << ": " << res << endl;
    }

    // 11:27:00
    // 11:28:09

    // 11:28:52 11:29

    // 5: 1225
    // 6: 8170
    // 7: 58981


    // for (int i = 1; i < N; ++i) {
    //     is_prime[i] = primes.lp[i] == i;
    // }
    // cout << primes.pr_n << endl;
    // int res = 0;
    // for (int i = 0; i < primes.pr_n; ++i) {
    //     int p = primes.pr[i];
    //     res += (is_prime>>p & is_prime).count() > 0;
    // }
    // cout << res << endl;
    // while (nt--) {
    //     cin >> n;
    //     // cout << Primes(n).pr.size() << endl;
    // }
}