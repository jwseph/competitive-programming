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
            char x = 'A'+(r+c)%2;
            char y = 'C'+(r+c)%2;
            a[r][c] = a[r][c] == x ? y : x;
        }
        cout << a[r] << endl;
    }
}