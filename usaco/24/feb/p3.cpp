#include <bits/stdc++.h>
using namespace std;

#define vr vector
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
using ll = long long;

const int N = 1e5+5, S = 60;
const ll D = 1e18;
int n, q;
int sz[N];
vr<vr<int>> gr(N), one(N);
vr<vr<ll>> grt(N);
vr<vr<vr<int>>> up(N);
vr<vr<vr<ll>>> upt(N);

vr<vr<bool>> vst(N);
void calc(int i, int t) {
    if (vst[i][t]) return;
    vst[i][t] = 1;

    int j = one[i][t];
    ll d = 1;
    while (sz[j] <= sz[i]) {
        int t1 = (t+d)%sz[j];
        calc(j, t1);
        if (sz[j] == sz[i]) {  // only runs once
            up[i][t][0] = j, upt[i][t][0] = d;
        }
        d += grt[j][t1], j = gr[j][t1];
        if (!j) return;
    }
    gr[i][t] = j, grt[i][t] = d;
}

int query(int i, ll t, ll d) {
    if (gr[i][t%sz[i]] && grt[i][t%sz[i]] <= d) {
        ll dt = grt[i][t%sz[i]];
        return query(gr[i][t%sz[i]], t+dt, d-dt);
    }
    t %= sz[i];
    for (int k = S-1; k >= 0; --k) {
        ll dt = upt[i][t][k];
        if (!up[i][t][k] || dt > d) continue;
        i = up[i][t][k];
        t += dt, t %= sz[i];
        d -= dt;
    }
    if (d) return query(one[i][t], t+1, d-1);
    return i;
}

int main() {
    cin >> n >> q;
    FOR(i, 1, n+1) {
        cin >> sz[i];
        one[i].resize(sz[i]);
        gr[i].resize(sz[i]);
        grt[i].resize(sz[i]);
        up[i].resize(sz[i], vr<int>(S));
        upt[i].resize(sz[i], vr<ll>(S));
        vst[i].resize(sz[i]);
    }
    FOR(i, 1, n+1) FOR(t, 0, sz[i]) cin >> one[i][t];
    FOR(i, 1, n+1) FOR(t, 0, sz[i]) calc(i, t);
    FOR(k, 1, S) FOR(i, 1, n+1) FOR(t, 0, sz[i]) {
        if (gr[i][t] && grt[i][t] <= (1ll<<k)) continue;
        int hi = up[i][t][k-1];
        if (!hi) continue;
        int ht = (t+upt[i][t][k-1])%sz[hi];
        if (!up[hi][ht][k-1]) continue;
        ll d = upt[i][t][k-1] + upt[hi][ht][k-1];
        if (d > D) continue;
        up[i][t][k] = up[hi][ht][k-1], upt[i][t][k] = d;
    }
    while (q--) {
        int i; ll t, d; cin >> i >> t >> d;
        cout << query(i, t, d) << endl;
    }
}