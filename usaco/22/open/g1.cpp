#include <bits/stdc++.h>
using namespace std;

int N, M;
map<int, int> cnt;
vector<tuple<int, int, int>> A, B;

int main() {
    // a <= x + t-t0 AND a >= x - (t-t0) == x - t+t0
    // a+t >= x+t0 AND a-t <= x-t0
    cin >> N;
    while (N--) {
        int q, t, x, n; cin >> q >> t >> x >> n;
        int a = x+t, b = x-t;
        (q == 2 ? A : B).push_back({a, b, n});
    }
    sort(begin(A), end(A));
    sort(begin(B), end(B));
    int j = 0;
    int res = 0;
    for (auto [a, b, n]: A) {
        while (j < B.size() && get<0>(B[j]) <= a) {
            auto [a1, b1, n1] = B[j];
            cnt[b1] += n1;
            ++j;
        }
        auto it = cnt.lower_bound(b);
        while (n && it != end(cnt)) {
            int take = min(n, it->second);
            it->second -= take;
            n -= take;
            res += take;
            if (!it->second) {
                cnt.erase(it);
                it = cnt.lower_bound(b);
            }
        }
    }
    cout << res << endl;
}