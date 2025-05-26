#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e7+1;

int nt, n;
bitset<N> is_prime;
vector<int> first_ok;

int main() {
    ofstream cout("B_precomputed.txt")

    for (int i = 0; i < N; ++i) is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < N; ++i) {
        if (!is_prime[i] || (ll)i*i >= N) continue;
        for (int j = i*i; j < N; j += i) {
            is_prime[j] = 0;
        }
    }

    // 11:49:50
    // 11:53:58

    // 7
    // 12:21:40
    // 12:21:
    
    // a+b=c
    // 
    // primes[i] is OK iff low_bit+primes[i] < N

    for (int i = 0; i < N; ++i) {
        if (!is_prime[i]) continue;
        bitset<N> tmp = is_prime;
        tmp >>= i;
        tmp &= is_prime;
        if (!tmp.count()) continue;
        int lo = tmp._Find_first();
        first_ok.push_back(lo+i);
    }
    sort(first_ok.begin(), first_ok.end());

    for (int x: first_ok) {

    }

    cin >> nt;
    for (int t = 1; t <= nt; ++t) {
        cin >> n;
        cout << "Case #" << t << ": ";
        
        int res = upper_bound(first_ok.begin(), first_ok.end(), n) - first_ok.begin();
        cout << res << endl;
    }
}