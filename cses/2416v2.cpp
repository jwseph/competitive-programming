#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define b back
#define F0R(i, n) for(i=0;i<n;++i)

int N,M,y,z,i,q,h,l;
const int W=3e5;
vector<pair<int, int>> Q[W];
vector<long long> S, P2{0}, A(W), P(W), R(W);

int main() {
    cin >> N >> M;
    F0R(i, N) {
        cin >> A[i];
        P[i+1] = P[i] + A[i];
    }
    F0R(q, M) {
        cin >> y >> z;
        Q[y-1].pb({z, q});
    }
    A[N] = 1e9;
    S.pb(N);
    for (l = N; l--;) {
        while (A[S.b()] <= A[l]) {
            S.pop_back();
            P2.pop_back();
        }
        P2.pb(P2.b() + (S.b()-l)*A[l] - P[S.b()]+P[l]);
        S.pb(l);
        for (auto [r, q]: Q[l]) {
            i = rend(S) - lower_bound(rbegin(S), rend(S), r), h = S[i];
            R[q] = P2.b()-P2[i] + (r-h)*A[h]-P[r]+P[h];
        }
    }
    F0R(q, M) cout << R[q] << endl;
}