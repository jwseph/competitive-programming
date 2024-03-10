#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(v): i, find_by_order(i): v

#define sz(x) int((x).size())

int N, K;
oset<int> S;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) S.insert(i);
    int i = 0;
    while (sz(S)) {
        i = (i+K) % sz(S);
        auto it = S.find_by_order(i);
        cout << *it+1 << ' ';
        S.erase(it);
    }
    cout << endl;
}