#include <bits/stdc++.h>
using namespace std;

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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class K, class V> using hmap = gp_hash_table<K, V, chash>;

int N, K;
hmap<int, int> idx;

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        int a; cin >> a;
        int j = idx[K-a];
        if (j) {
            cout << j << ' ' << i << endl;
            return 0;
        }
        idx[a] = i;
    }
    cout << "IMPOSSIBLE" << endl;
}