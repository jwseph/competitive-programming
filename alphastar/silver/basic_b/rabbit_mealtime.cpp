#include <bits/stdc++.h>
using namespace std;

#define N_MAX 1000
#define ll long long

ll N, M, R[N_MAX][2], S[N_MAX][2];
bool V[N_MAX]{};

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
ll dist(int s, int r) {
    return dist(R[r][0], R[r][1], S[s][0], S[s][1]);
}

int main() {
    cin >> N >> M;
    if (N == M) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        cin >> R[i][0] >> R[i][1];
    }
    for (int i = 0; i < M; ++i) {
        cin >> S[i][0] >> S[i][1];
    }
    for (int s = 0; s < M; ++s) {
        ll md = LONG_MAX;
        int mr = -1;
        for (int r = 0; r < N; ++r) {
            if (V[r]) continue;
            ll d = dist(s, r);
            if (d < md) {
                md = d;
                mr = r;
            }
        }
        V[mr] = true;
    }
    for (int i = 0; i < N; ++i) {
        if (!V[i]) {
            cout << i+1 << endl;
        }
    }
}