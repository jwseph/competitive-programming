#include <bits/stdc++.h>
using namespace std;

using Node = pair<int, void*>;

const int N = 1e3+3;

int n, m, a[N], b[N], dp[N][N];
Node nodes[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                nodes[i][j] = {a[i], &nodes[i-1][j-1]};
            } else if (dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                nodes[i][j].second = &nodes[i-1][j];
            } else {
                dp[i][j] = dp[i][j-1];
                nodes[i][j].second = &nodes[i][j-1];
            }
        }
    }
    stack<int> s;
    for (auto p = &nodes[n][m]; p->second; p = (Node*)p->second) {
        if (p->first) s.push(p->first);
    }
    cout << s.size() << endl;
    while (s.size()) {
        cout << s.top() << ' ';
        s.pop();
    }
}