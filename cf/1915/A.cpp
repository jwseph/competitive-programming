#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    while (N--) {
        int a, b, c; cin >> a >> b >> c;
        if (a != b && a != c) cout << a << endl;
        if (b != a && b != c) cout << b << endl;
        if (c != a && c != b) cout << c << endl;
    }
}