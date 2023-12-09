#include <bits/stdc++.h>
using namespace std;

int NT;

int sol(int a, int b, int c) {
    int d = abs(b-c);
    return d%2 == 0 && a;
}

int main() {
    cin >> NT;
    while (NT--) {
        int a, b, c; cin >> a >> b >> c;
        cout << sol(a, b, c) << ' ' << sol(b, a, c) << ' ' << sol(c, a, b) << endl;
    }
}