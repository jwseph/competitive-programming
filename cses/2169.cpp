#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(v): i, find_by_order(i): v

#define sz(x) int((x).size())

using pii = pair<int, int>;
const int MAXN = 2e5+5;

int N, res[MAXN];
vector<array<int, 3>> A;
oset<pii> S;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int l, r; cin >> l >> r;
        A.push_back({-l, r, i});
    }
    sort(begin(A), end(A));
    for (int j = 0; j < sz(A); ++j) {
        auto [l, r, i] = A[j];
        pii p = {r, j};
        S.insert(p);
        res[i] = S.order_of_key(p);
    }
    for (int i = 0; i < N; ++i) cout << res[i] << ' ';
    cout << endl;
    S = {};
    for (int j = sz(A)-1; j >= 0; --j) {
        auto [l, r, i] = A[j];
        pii p = {r, j};
        S.insert(p);
        res[i] = sz(S)-1-S.order_of_key(p);
    }
    for (int i = 0; i < N; ++i) cout << res[i] << ' ';
    cout << endl;
}