#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
using t3i = array<int, 3>;

int N, res[MAXN], K = 0;
vector<t3i> A;
queue<int> Q;

int main() {
    // time, type, customer
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int l, r; cin >> l >> r;
        A.push_back({l, 0, i});
        A.push_back({r, 1, i});
    }
    sort(begin(A), end(A));
    for (auto [t, l, i]: A) {
        if (l) {
            Q.push(res[i]);
            continue;
        }
        if (Q.empty()) Q.push(++K);
        res[i] = Q.front();
        Q.pop();
    }
    cout << K << endl;
    for (int i = 0; i < N; ++i) cout << res[i] << ' ';
    cout << endl;
}