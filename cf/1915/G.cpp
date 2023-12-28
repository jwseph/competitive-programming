#include <bits/stdc++.h>
using namespace std;

#define MAXN 1003
#define ll long long
#define t3i tuple<ll, int, int>

int NT, N, M;

int main() {
    // Simple dijkstra
    cin >> NT;
    while (NT--) {
        cin >> N >> M;
        bool V[N][MAXN];
        memset(V, 0, sizeof V);
        vector<pair<int, int>> A[N];
        for (int e = 0; e < M; ++e) {
            int i, j, w; cin >> i >> j >> w; --i; --j;
            A[i].push_back({j, w});
            A[j].push_back({i, w});
        }
        int S[N];
        for (int i = 0; i < N; ++i) {
            cin >> S[i];
        }
        priority_queue<t3i, vector<t3i>, greater<>> Q;
        Q.push({0ll, 1001, 0});
        while (Q.size()) {
            auto [t, s, i] = Q.top();
            Q.pop();
            s = min(s, S[i]);
            if (V[i][s]) continue;
            V[i][s] = 1;
            if (i == N-1) {
                cout << t << endl;
                break;
            }
            for (auto [j, w]: A[i]) {
                if (V[j][s]) continue;
                ll dt = (ll)w*s;
                Q.push({t+dt, s, j});
            }
        }
    }
}