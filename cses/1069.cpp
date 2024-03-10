#include <bits/stdc++.h>
using namespace std;

int main() {
    int res = 0, cur = 0;
    char p = '.', c;
    while (cin >> c) {
        if (c != p) cur = 0;
        p = c;
        ++cur;
        res = max(res, cur);
    }
    cout << res << endl;
}