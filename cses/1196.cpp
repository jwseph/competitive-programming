#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class K> using heap = priority_queue<K, vector<K>, greater<>>;

const int MAXN = 1e5+5;
int N, M, K, V[MAXN];
vector<pair<int, int>> A[MAXN];
vector<ll> res;
heap<pair<ll, int>> Q;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    for (int e = 0; e < M; ++e) {
        int i, j, t; cin >> i >> j >> t;
        A[i].push_back({j, t});
    }
    Q.push({0, 1});
    while (Q.size()) {
        auto [t, i] = Q.top(); Q.pop();
        if (V[i] >= K) continue;
        ++V[i];
        if (i == N) res.push_back(t);
        for (auto [j, dt]: A[i]) {
            Q.push({t+dt, j});
        }
    }
    for (ll t: res) cout << t << ' ';
    cout << endl;
}