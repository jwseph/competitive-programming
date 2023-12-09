#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N[3];
vector<int> R[3], C[3];
unordered_set<ll> V;
queue<ll> Q;

bool done(vector<int> dr, vector<int> dc) {
    vector<vector<int>> v;
    for (int o = 0; o < 3; ++o) {
        int lr = dr[o] + *min_element(begin(R[o]), end(R[o]));
        int rr = dr[o] + *max_element(begin(R[o]), end(R[o]));
        int lc = dc[o] + *min_element(begin(C[o]), end(C[o]));
        int rc = dc[o] + *max_element(begin(C[o]), end(C[o]));
        v.push_back({lr, rr, lc, rc});
    }
    for (int o1 = 0; o1 < 3; ++o1) {
        for (int o2 = o1+1; o2 < 3; ++o2) {
            int lr1 = v[o1][0], rr1 = v[o1][1], lc1 = v[o1][2], rc1 = v[o1][3];
            int lr2 = v[o2][0], rr2 = v[o2][1], lc2 = v[o2][2], rc2 = v[o2][3];
            if (rr2 < lr1 || rr1 < lr2 || rc2 < lc1 || rc1 < lc2) continue;
            return 0;
        }
    }
    return 1;
}

bool check(vector<int> dr, vector<int> dc) {
    bool vst[31][31]{};
    for (int o = 0; o < 3; ++o) {
        if (dr[o] < -10 || dr[o] > 10 || dc[o] < -10 || dc[o] > 10) return 0;
        for (int i = 0; i < R[o].size(); ++i) {
            int r = R[o][i]+dr[o]+10, c = C[o][i]+dc[o]+10;
            if (r < 0 || r >= 31 || c < 0 || c >= 31) return 0;
            if (vst[r][c]) return 0;
            vst[r][c] = 1;
        }
    }
    return 1;
}

void add(vector<int> dr, vector<int> dc) {
    if (!check(dr, dc)) return;
    ll i = 0;
    for (int o = 0; o < 3; ++o) {
        int a = dr[o]+10, b = dc[o]+10;
        i *= 21; i += a;
        i *= 21; i += b;
    }
    if (V.find(i) != V.end()) return;
    V.insert(i);
    Q.push(i);
}

int main() {
    cin >> N[0] >> N[1] >> N[2];
    for (int o = 0; o < 3; ++o) {
        for (int i = 0; i < N[o]; ++i) {
            int r, c; cin >> r >> c;
            R[o].push_back(r);
            C[o].push_back(c);
        }
    }
    add({0, 0, 0}, {0, 0, 0});
    for (int res = 0; Q.size(); ++res) for (int qs = Q.size(); qs > 0; --qs) {
        ll i = Q.front();
        Q.pop();
        int b3 = i%21-10; i /= 21; int a3 = i%21-10; i /= 21;
        int b2 = i%21-10; i /= 21; int a2 = i%21-10; i /= 21;
        int b1 = i%21-10; i /= 21; int a1 = i%21-10; i /= 21;
        vector<int> inp[2] = {{a1, a2, a3}, {b1, b2, b3}};
        if (done(inp[0], inp[1])) {
            cout << res << endl;
            return 0;
        }
        for (int r = 0; r < 2; ++r) {
            for (int c = 0; c < 3; ++c) {
                for (int d = -1; d <= 1; d += 2) {
                    inp[r][c] += d;
                    add(inp[0], inp[1]);
                    inp[r][c] -= d;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}