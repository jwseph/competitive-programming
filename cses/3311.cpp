#include <bits/stdc++.h>
using namespace std;

int n, m;
string a[502];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            set<char> s;
            if (r) s.insert(a[r-1][c]);
            if (c) s.insert(a[r][c-1]);
            s.insert(a[r][c]);
            for (char x = 'A'; x <= 'D'; ++x) {
                if (!s.count(x)) {
                    a[r][c] = x;
                    break;
                }
            }
        }
        cout << a[r] << endl;
    }
}