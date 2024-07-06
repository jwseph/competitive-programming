#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(v): i, find_by_order(i): v

int main() {
    oset<int> S;
    S.insert(1);
    S.insert(5);
    S.insert(9);
    cout << S.order_of_key(6) << endl;
}