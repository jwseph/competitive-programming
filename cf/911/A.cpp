#include <bits/stdc++.h>
using namespace std;

int NT;

int sol(string S) {
    int res = 0, cur = 0;
    bool inf = 0;
    for (char C: S) {
        if (C == '#') {
            if (cur >= 3) inf = 1;
            res += min(cur, 2);
            cur = 0;
            continue;
        }
        ++cur;
    }
    if (inf) return 2;
    return res;
}

int main() {
    cin >> NT;
    while (NT--) {
        int L; cin >> L;
        string S; cin >> S;
        S += '#';
        reverse(begin(S), end(S));
        S += '#';
        cout << sol(S) << endl;
    }
}