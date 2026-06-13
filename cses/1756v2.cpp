#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int i, j; cin >> i >> j;
        if (i > j) swap(i, j);
        cout << i << ' ' << j << endl;
    }
}