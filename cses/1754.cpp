#include <bits/stdc++.h>
using namespace std;

int T;

bool sol(int a, int b) {
    if ((a+b)%3) return 0;
    if (a > b) swap(a, b);
    if (a*2 < b) return 0;
    return 1;
}

int main() {
    cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        cout << (sol(a, b) ? "YES" : "NO") << endl;
    }
}