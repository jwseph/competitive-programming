#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pli = pair<ll, int>;

const int MAXN = 1e5+5;
int N, M;
vector<pli> A[MAXN];
ll V[MAXN];
priority_queue<pli, vector<pli>, greater<>> Q;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j, t; cin >> i >> j >> t; --i, --j;
        A[i].push_back({j, t});
    }
    Q.push({0, 0});
    while (Q.size()) {
        auto [t, i] = Q.top();
        Q.pop();
        if (V[i]) continue;
        V[i] = t;
        for (auto [j, dt]: A[i]) {
            if (j == 0 || V[j]) continue;
            Q.push({t+dt, j});
        }
    }
    for (int i = 0; i < N; ++i) cout << V[i] << ' ';
    cout << endl;
}