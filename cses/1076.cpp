#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(v): i, find_by_order(i): v

const int MAXN = 2e5+5;
using pii = array<int, 2>;

template<class T>
struct MedianSet {
    using ll = long long;
    oset<pair<T, int>> S;
    map<T, int> cnt;
    pair<T, int> m;
    ll cost = 0; T median;
    void insert(T v) { insert({v, cnt[v]++}); }
    void insert(pair<T, int> p) {
        cost += abs(p.first-m.first);
        S.insert(p);
        update();
    }
    void erase(T v) { erase({v, --cnt[v]}); }
    void erase(pair<T, int> p) {
        cost -= abs(p.first-m.first);
        S.erase(p);
        update();
    }
    void update() {
        if (!size()) return;
        ll l = (size()-1)/2, r = size()-1-l;
        pair<T, int> n = *S.find_by_order(l);
        ll d = abs(m.first-n.first);
        cost += d * (n < m ? (r-(l+1)) : n > m ? (l-(r+1)) : 0);
        m = n, median = m.first;
    }
    int size() {
        return S.size();
    }
};

int N, K, A[MAXN];
MedianSet<int> S;

int main() {
    cin >> N >> K;
    for (int i = 0, j = 0; j < N; ++j) {
        cin >> A[j];
        S.insert({A[j], j});
        if (S.size() > K) {
            S.erase({A[i], i});
            ++i;
        }
        if (S.size() == K) {
            cout << S.median << ' ';
        }
    }
    cout << endl;
}