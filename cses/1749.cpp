#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(v): i, find_by_order(i): v

int N;
oset<pair<int, int>> S;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        S.insert({i, a});
    }
    while (N--) {
        int i; cin >> i; --i;
        auto it = S.find_by_order(i);
        cout << it->second << ' ';
        S.erase(it);
    }
    cout << endl;
}