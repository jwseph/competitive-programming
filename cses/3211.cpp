#include <bits/stdc++.h>
using namespace std;

int n, a[200005];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // gaussian elimination
    int p = 0;
    for (int j = 30; j >= 0; --j) {
        int k = -1;
        for (int i = p; i < n; ++i) {
            if (a[i]&1<<j) k = i;
        }
        if (k < 0) continue;
        swap(a[k], a[p]);
        for (int i = p+1; i < n; ++i) {
            if (a[i]&1<<j) a[i] ^= a[p];
        }
        p++;
    }
    cout << (1<<p) << endl;
    // backwards sweep
    while (p --> 0) {
        int j = 30;
        while ((a[p]&1<<j) == 0) j--;

        for (int i = 0; i < p; ++i) {
            if (a[i]&1<<j) a[i] ^= a[p];
        }
    }
}