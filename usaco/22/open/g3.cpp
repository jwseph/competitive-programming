#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int NT, B, N, L[MAXN], R[MAXN];
vector<int> A[MAXN];
int res;

pair<int, int> dfs(int i) {
    int l = 0, r = 1e9;
    for (int j: A[i]) {
        auto [l1, r1] = dfs(j);
        l = max(l, l1);
        r = min(r, r1);
    }
    int h = max(L[i], min(R[i], (l+r)/2));
    int cur = max(h-r, l-h);
    res = max(res, cur);
    l = max(l, L[i]);
    r = min(r, R[i]);
    return {l, r};
}

int main() {
    cin >> NT >> B;
    while (NT--) {
        res = 0;
        cin >> N;
        for (int i = 0; i < N; ++i) A[i] = {};
        for (int i = 1; i < N; ++i) {
            int p; cin >> p; --p;
            A[p].push_back(i);
        }
        for (int i = 0; i < N; ++i) cin >> L[i] >> R[i];
        auto [l, r] = dfs(0);
        cout << res << endl;
        if (B) {
            for (int i = 0; i < N; ++i) {
                int h = max(L[i], min(R[i], (l+r)/2));
                cout << h;
                if (i < N-1) cout << ' ';
            }
            cout << endl;
        }
    }
}