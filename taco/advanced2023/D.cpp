#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5+5;
int n, l, r;
int a[N];
ll res;

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n, greater<int>());
    for (int i = 0; i < r-l+1; ++i) {
        res += a[i];
    }
    cout << res << endl;
}