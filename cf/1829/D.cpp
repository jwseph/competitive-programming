#include <bits/stdc++.h>
using namespace std;

int T;

bool sol(int n, int m) {
    while (n%3 == 0 && m%3 == 0) n /= 3, m /= 3;
    while (n%2 == 0 && m%2 == 0) n /= 2, m /= 2;
    while (n%3 == 0) {
        if (m%2 == 0) m /= 2;
        n /= 3;
    }
    return n == m;
}

int main() {
    cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        cout << (sol(n, m) ? "YES" : "NO") << endl;
    }
}