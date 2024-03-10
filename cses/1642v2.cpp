#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
using t3i = array<int, 3>;

const int MAXN = 1e3+5;

int N, K, A[MAXN];
vector<t3i> S;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            S.push_back({A[i]+A[j], i+1, j+1});
        }
    }
    sort(all(S));
    for (auto [p, i, j]: S) {
        t3i a = {K-p, 0, 0}, b = {K-p, INT_MAX, INT_MAX};
        auto lt = lower_bound(all(S), a);
        auto rt = upper_bound(all(S), b);
        for (auto it = lt; it != rt; ++it) {
            auto [q, l, r] = *it;
            if (K-p != q) continue;
            if (i >= j || j >= l || l >= r) continue;
            cout << i << ' ' << j << ' ' << l << ' ' << r << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}