#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] ^= a[i-1];
    }
    int res = 0;
    for (int j = 31; j >= 0; --j) {
        res <<= 1;
        unordered_set<int> pre;
        for (int i = 0; i <= n; ++i) {
            int p = a[i]>>j;
            if (pre.count(res^1^p)) res |= 1;
            pre.insert(p);
        }
    }
    cout << res << endl;
}