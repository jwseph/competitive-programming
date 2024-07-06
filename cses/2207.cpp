#include <bits/stdc++.h>
using namespace std;

const int N = 2e4+5;
int n = 2e3, nt;
int gr[N], mex[N];

int main() {
    for (int h = 2; h <= n; ++h) {
        for (int i = 1; i < (h+1)/2; ++i) {
            mex[gr[i]^gr[h-i]] = h;
        }
        for (int i = 0; i < N; ++i) {
            if (mex[i] == h) continue;
            gr[h] = i;
            break;
        }
    }
    cin.tie(0)->sync_with_stdio(0);
    cin >> nt;
    while (nt--) {
        int h; cin >> h;
        cout << (h >= n || gr[h] ? "first" : "second") << endl;
    }
}