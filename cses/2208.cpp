#include <bits/stdc++.h>
using namespace std;

int nt, n;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> nt;
    while (nt--) {
        cin >> n;
        int res = 0;
        while (n--) {
            int a; cin >> a;
            res |= a&1;
        }
        cout << (res ? "first" : "second") << endl;
    }
}