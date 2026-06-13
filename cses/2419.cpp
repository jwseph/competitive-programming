#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    // C(i, j) % 2 == ((i&j) == j)
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        int b = (n-1&i) == i;
        res ^= b*x;
    }
    cout << res << endl;
}