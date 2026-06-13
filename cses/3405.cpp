#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k, x, a, b, c;
int bits[31];

void insert(int v)  {
    for (int i = 0; i < 31; ++i) {
        bits[i] += v>>i&1;
    }
}

void erase(int v) {
    for (int i = 0; i < 31; ++i) {
        bits[i] -= v>>i&1;
    }
}

int get() {
    int res = 0;
    for (int i = 0; i < 31; ++i) {
        res |= (bits[i] > 0) << i;
    }
    return res;
}

int main() {
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    ll y = x, z = x;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        // insert
        insert(y);
        y = (y*a+b) % c;
        if (i-k >= 0) {
            // erase
            erase(z);
            z = (z*a+b) % c;
        }
        if (i >= k-1) {
            // print
            res ^= get();
        }
    }
    cout << res << endl;
}