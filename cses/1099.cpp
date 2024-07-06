#include <bits/stdc++.h>
using namespace std;

int nt, n;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> nt;
    while (nt--) {
        cin >> n;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            if (i%2 == 0) continue;
            res ^= a;
        }
        cout << (res ? "first" : "second") << endl;
    }
}