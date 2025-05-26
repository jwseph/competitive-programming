#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 4e5+5, L = 20;
int n, p[N][L];
ll k, a[N];

int sol(int start) {
    // Find number of jumps from start for at least start+n/2.
    int pos = start, res = 0;
    for (int j = L-1; j >= 0; --j) {
        if (p[pos][j] < start+n/2) {
            pos = p[pos][j];
            res += 1<<j;
        }
    }
    return res+1;
}

int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < L; ++j) {
            p[i][j] = INT_MAX;
        }
    }
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    n *= 2;
    p[n][0] = n;
    for (int i = n-1, j = n; i >= 0; --i) {
        k -= a[i];
        while (k < 0) {
            k += a[--j];
        }
        p[i][0] = j;
    }
    for (int j = 1; j < L; ++j) {
        for (int i = 0; i <= n; ++i) {
            p[i][j] = p[p[i][j-1]][j-1];
        }
    }
    int res = INT_MAX;
    for (int i = 0; i < n/2; ++i) {
        res = min(res, sol(i));
    }
    cout << res << endl;
}