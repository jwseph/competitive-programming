#include <bits/stdc++.h>
using namespace std;

using arr2 = array<int, 2>;

int n, t[1003][1003], v[1003][1003];
queue<arr2> q;

int main() {
    cin >> n;
    v[0][0] = 1;
    q.push({0, 0});
    for (int d = 0; q.size(); ++d) {
        for (int qs = q.size(); qs --> 0;) {
            auto [r, c] = q.front(); q.pop();
            t[r][c] = d;
            for (int a = -1; a <= 1; a += 2) {
                for (int b = -1; b <= 1; b += 2) {
                    for (int d = 1; d <= 2; ++d) {
                        int e = 3-d;
                        int i = r+a*d, j = c+b*e;
                        if (i < 0 || i >= n || j < 0 || j >= n) continue;
                        if (v[i][j]) continue;
                        v[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }
    }
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << t[r][c] << ' ';
        }
        cout << endl;
    }
}