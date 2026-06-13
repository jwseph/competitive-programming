#include <bits/stdc++.h>
using namespace std;

set<int> s, res;
int n, pre[200005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> pre[i];
        pre[i] ^= pre[i-1];
    }
    s = {0};
    for (int i = 1; i <= n; ++i) {
        for (int p: s) {
            res.insert(p^pre[i]);
        }
        s.insert(pre[i]);
    }
    cout << res.size() << endl;
    for (int x: res) {
        cout << x << ' ';
    }
}