#include <bits/stdc++.h>
using namespace std;

int sol(int n, int s, int k) {
    if (s+k*2 < n) return s+k*2;
    int t = (n-s+1)/2;
    return 1-s+2*sol(n-t, (s+n)%2, k-t);
}

int m;

int main() {
    cin >> m;
    while (m--) {
        int n, k; cin >> n >> k; --k;
        cout << sol(n, 1, k) + 1 << endl;
    }
}