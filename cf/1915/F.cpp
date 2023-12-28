#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define MAXN 200005
#define ll long long

int NT, N;

int main() {
    // Number of complete overlaps
    cin >> NT;
    while (NT--) {
        cin >> N;
        vector<pair<int, int>> A;
        for (int i = 0; i < N; ++i) {
            int l, r; cin >> l >> r;
            A.push_back({l, r});
        }
        sort(begin(A), end(A));
        oset<int> S;
        ll res = 0;
        for (auto [l, r]: A) {
            // find number of rs greater than
            res += S.size() - S.order_of_key(r);
            S.insert(r);
        }
        cout << res << endl;
    }
}