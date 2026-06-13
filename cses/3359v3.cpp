#include <bits/stdc++.h>
using namespace std;

int n;
string a[3003];
bool v[3003][3003];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<array<int, 2>> q;
    v[0][0] = 1;
    q.push_back({0, 0});
    for (int d = 0; d < n*2-1; d++) {
        char lo = 'Z'+1;
        for (auto [r, c]: q) {
            lo = min(lo, a[r][c]);
        }
        cout << lo;

        vector<array<int, 2>> q_next;
        for (auto [r, c]: q) {
            if (a[r][c] != lo) continue;
            if (r+1 < n && !v[r+1][c]) {
                v[r+1][c] = 1;
                q_next.push_back({r+1, c});
            }
            if (c+1 < n && !v[r][c+1]) {
                v[r][c+1] = 1;
                q_next.push_back({r, c+1});
            }
        }
        q = move(q_next);
    }
    cout << endl;
}