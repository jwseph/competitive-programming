#include <bits/stdc++.h>
using namespace std;

#define MAXN 2003
#define ll long long

typedef pair<int, int> fr;
fr make_fr(int n, int d) {
    if (d < 0) d = -d, n = -n;
    return {n, d};
}
bool cmp(const fr& a, const fr& b) {
    return (ll)a.first*b.second < (ll)b.first*a.second;
}

int N, Q, A[MAXN], res = 0;
map<int, fr> L[MAXN], R[MAXN];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) {
        fr r = make_fr(1, 0);
        L[i][i] = r;
        for (int j = i-1; j >= 0; --j) {
            fr c = make_fr(A[i]-A[j], i-j);
            if (!cmp(r, c)) {
                r = c;
                L[i][j] = c;
                R[j][i] = c;
                ++res;
            }
        }
    }
    cin >> Q;
    while (Q--) {
        int i, dh; cin >> i >> dh; --i;
        A[i] += dh;

        fr r = make_fr(1, 0);
        for (int j = i-1; j >= 0; --j) {
            fr c = make_fr(A[i]-A[j], i-j);
            if (!cmp(r, c)) {
                r = c;
                if (L[i].find(j) == L[i].end()) ++res;
                L[i][j] = c;
                R[j][i] = c;

                auto tmp = R[j].lower_bound(i);
                auto it = tmp; ++it;
                while (it != R[j].end() && cmp(it->second, c)) {
                    int k = it->first;
                    R[j].erase(it);
                    L[k].erase(j);
                    --res;
                    it = tmp; ++it;
                }
            }
        }

        r = make_fr(-1, 0);
        for (int j = i+1; j < N; ++j) {
            fr c = make_fr(A[i]-A[j], i-j);
            if (!cmp(c, r)) {
                r = c;
                if (R[i].find(j) == R[i].end()) ++res;
                R[i][j] = c;
                L[j][i] = c;

                auto tmp = L[j].lower_bound(i);
                auto it = tmp;
                while (it != L[j].begin() && cmp(c, (--it)->second)) {
                    int k = it->first;
                    L[j].erase(it);
                    R[k].erase(j);
                    --res;
                    it = tmp;
                }
            }
        }

        cout << res << endl;
    }
}