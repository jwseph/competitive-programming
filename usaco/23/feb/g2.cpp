#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define pii pair<int, int>
#define int long long

int N, R, G[MAXN];
pii dp[MAXN][2];
vector<int> A[MAXN];

void dfsg(int i) {
    for (int j: A[i]) {
        dfsg(j);
        G[i] += G[j];
    }
}

pii dfs(int i, int r) {  // return time, fertilizer needed
    pii unset = {-1, -1};
    if (dp[i][r] != unset) return dp[i][r];
    auto& S = A[i];
    sort(begin(S), end(S), [&](int j1, int j2) {
        auto [t1, f1] = dfs(j1, 0); int g1 = G[j1];
        auto [t2, f2] = dfs(j2, 0); int g2 = G[j2];
        int ans1 = 1*g1+(3+t1)*g2, ans2 = 1*g2+(3+t2)*g1;
        return ans1 < ans2;
    });
    int K = S.size();

    int t0 = 0;
    pii P[K+1]; P[0] = {t0, 0};
    int PG[K+1]; PG[0] = 0;

    for (int p = 0; p < K; ++p) {
        int j = S[p], g = G[j];
        auto [t, f] = dfs(j, 0);
        t0 += 1;
        f += g*t0 + P[p].second;
        t0 += t+1;
        P[p+1] = {t0, f};
        PG[p+1] = PG[p] + g;
    }

    pii res = P[K];
    if (r == 0) return dp[i][r] = res;
    for (int p = 0; p < K; ++p) {
        int j = S[p], g = G[j];
        int dt = P[p+1].first-P[p].first;
        pii lp = P[p];
        pii rp = {P[K].first-P[p+1].first, P[K].second-P[p+1].second - dt*(PG[K]-PG[p+1])};
        pii hp = dfs(j, 1);
        int tf = 1+P[K].first-P[p+1].first+P[p].first-P[0].first;  // 1 for crossing edge
        hp.first += 1;
        hp.second += tf * g;
        pii cur = {lp.first+rp.first+hp.first, lp.second+rp.second+hp.second};
        res = min(res, cur);
    }
    return dp[i][r] = res;
}

signed main() {
    cin >> N >> R;
    G[0] = 0;
    for (int i = 1; i < N; ++i) {
        int p, g; cin >> p >> g; --p;
        A[p].push_back(i);
        G[i] = g;
    }
    dfsg(0);
    for (int i = 0; i < N; ++i) {
        for (int r = 0; r < 2; ++r) {
            dp[i][r] = {-1, -1};
        }
    }
    pii res = dfs(0, R);
    cout << res.first << ' ' << res.second << endl;
}