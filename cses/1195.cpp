#include <bits/stdc++.h>
using namespace std;

template<int N> using tl = array<long long, N>;
template<class K> using heap = priority_queue<K, vector<K>, greater<>>;

const int MAXN = 1e5+5;
int N, M;
vector<tl<2>> A[MAXN];
heap<tl<3>> Q;
bool V[MAXN][2];

int main() {
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j, t; cin >> i >> j >> t;
        A[i].push_back({j, t});
    }
    Q.push({0, 1, 0});
    while (Q.size()) {
        auto [t, i, u] = Q.top(); Q.pop();
        if (i == N && u) {
            cout << t << endl;
            return 0;
        }
        if (V[i][u]) continue;
        V[i][u] = 1;
        for (auto [j, dt]: A[i]) {
            Q.push({t+dt, j, u});
            if (!u) Q.push({t+dt/2, j, 1});
        }
    }
}