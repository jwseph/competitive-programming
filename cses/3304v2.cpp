#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int L = 18;

int n, nq, a[N];
int up[L][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> nq;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    stack<int> s;
    a[n+1] = 2e9;
    up[0][n+1] = n+1;
    s.push(n+1);
    for (int i = n; i >= 1; --i) {
        while (a[i] >= a[s.top()]) s.pop();
        up[0][i] = s.top();
        s.push(i);
    }
    for (int j = 1; j < L; ++j) {
        for (int i = 1; i <= n+1; ++i) {
            up[j][i] = up[j-1][up[j-1][i]];
        }
    }
    while (nq--) {
        int l, r; cin >> l >> r;
        int i = l, res = 1;
        for (int j = L-1; j >= 0; --j) {
            if (up[j][i] <= r) {
                i = up[j][i];
                res += 1<<j;
            }
        }
        cout << res << endl;
    }
}