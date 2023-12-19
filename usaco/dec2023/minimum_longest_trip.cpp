#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define MAXM 400005
#define ll long long

int N, M, OUT[MAXN]{};
vector<pair<int, ll>> IN[MAXN];
queue<int> Q;
tuple<int, ll, ll, ll> R[MAXN];

int main() {
    // Topo sort
    cin >> N >> M;
    while (M--) {
        int a, b, l; cin >> a >> b >> l; --a; --b;
        ++OUT[a];
        IN[b].push_back({a, l});
    }
    for (int i = 0; i < N; ++i) {
        R[i] = {-N, 0ll, 0ll, 0ll};
        if (OUT[i] == 0) {
            Q.push(i);
        }
    }
    while (Q.size()) {
        int i = Q.front();
        Q.pop();
        auto [cur, tl, t2l, ts] = R[i];
        for (auto [j, l]: IN[i]) {
            R[j] = min(R[j], {cur-1, l, tl, ts+l});
            if (--OUT[j] == 0) {
                Q.push(j);
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        auto [cur, tl, t2l, ts] = R[i];
        cout << ((-cur)%N) << ' ' << ts << endl;
    }
}