#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>; // i == order_of_key(v), v == *find_by_order(i)

oset<pair<int, int>> s;
int n, k, a[200005];
long long inv = 0;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        inv += s.size() - s.order_of_key({a[i], INT_MAX});
        s.insert({a[i], i});
        if (i-k >= 0) {
            s.erase(s.find({a[i-k], i-k}));
            inv -= s.order_of_key({a[i-k], INT_MIN});
        }
        if (i >= k-1) {
            cout << inv << ' ';
        }
    }
}