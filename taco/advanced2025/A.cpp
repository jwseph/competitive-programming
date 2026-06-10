#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int np, n, k;
int s[N], v[N], cnt[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> np >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> v[i];
    }
    for (int i = n-1; i >= 0; --i) {
        if (s[i] == 0 || s[i] == k) {
            swap(s[i], s[n-1]);
            swap(v[i], v[n-1]);
            --n;
        }
    }
    int t;
    for (t = 0; n; ++t) {
        // Clean up finished ants
        for (int i = n-1; i >= 0; --i) {
            s[i] += v[i];
            s[i] %= np;
            if (s[i] == 0 || s[i] == k) {
                swap(s[i], s[n-1]);
                swap(v[i], v[n-1]);
                --n;
            }
        }
    }
    cout << t << endl;
}