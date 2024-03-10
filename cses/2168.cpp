#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int N;
bool res[MAXN];
vector<array<int, 3>> A;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int l, r; cin >> l >> r;
        A.push_back({-l, r, i});
    }
    sort(begin(A), end(A));
    int m = INT_MAX;
    for (auto [l, r, i]: A) {
        res[i] = m <= r;
        m = min(m, r);
    }
    for (int i = 0; i < N; ++i) cout << res[i] << ' ';
    cout << endl;
    reverse(begin(A), end(A));
    m = INT_MIN;
    for (auto [l, r, i]: A) {
        res[i] = m >= r;
        m = max(m, r);
    }
    for (int i = 0; i < N; ++i) cout << res[i] << ' ';
    cout << endl;
}