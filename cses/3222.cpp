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
template<class K, class V> using umap = unordered_map<K, V, chash>;
template<class K> using uset = unordered_set<K, chash>;
template<class K> using heap = priority_queue<K, vector<K>, greater<>>;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>; // i == order_of_key(v), v == *find_by_order(i)
template<class K, class V> using hmap = gp_hash_table<K, V, chash>;

hmap<int, int> cnt;
int n, k, a[200005];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        if (i-k >= 0) {
            if (!--cnt[a[i-k]]) {
                cnt.erase(a[i-k]);
            }
        }
        if (i >= k-1) {
            cout << cnt.size() << ' ';
        }
    }
}