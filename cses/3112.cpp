#include <bits/stdc++.h>
using namespace std;

int main() {
    int l = 1, r = 1e9;
    while (l < r) {
        int h = (l+r)/2;
        cout << "? " << h << endl;
        string s; cin >> s;
        if (s == "YES") {
            l = h+1;
        } else {
            r = h;
        }
    }
    cout << "! " << l << endl;
}