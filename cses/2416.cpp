#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define ll long long
#define pb push_back

int N, NQ, A[MAXN];
ll P[MAXN], res[MAXN];
vector<pair<int, int>> Q[MAXN];
vector<int> S;
vector<ll> P2 = {0};

int main() {
    cin >> N >> NQ;
    P[0] = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        P[i+1] = P[i] + A[i];
    }
    for (int q = 0; q < NQ; ++q) {
        int l, r; cin >> l >> r; --l;
        Q[l].pb({r, q});
    }
    A[N] = INT_MAX;
    S.pb(N);
    for (int l = N-1; l >= 0; --l) {
        while (A[S.back()] <= A[l]) {
            S.pop_back();
            P2.pop_back();
        }
        P2.pb(P2.back() + (ll)(S.back()-l)*A[l] - (P[S.back()]-P[l]));
        S.pb(l);
        for (auto [r, q]: Q[l]) {
            int i = lower_bound(begin(S), end(S), r, greater<>()) - begin(S);
            ll full = P2.back() - P2[i];
            int h = S[i];
            ll part = (ll)(r-h)*A[h] - (P[r]-P[h]);
            res[q] = full+part;
        }
    }
    for (int q = 0; q < NQ; ++q) cout << res[q] << endl;
}