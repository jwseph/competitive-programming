#include <bits/stdc++.h>
using namespace std;

int nt;

int main() {
    cin >> nt;
    while (nt--) {
        int n, a, b; cin >> n >> a >> b;
        // all cards must be played
        // max score is n-1, 1
        // n-1, 0 is impossible
        // 0 means other player must have 0
        // a+b must be even
        // well, is 2, 1 possible
        // 1-2 2-3 3-1
        // . . . . . . . 
        //  X   X   / /   solves a=4, b=3 bite of min 1       2, 1 zigzag 2, 2 X
        // . . . . . . .
        //
        // . . . . . . . a=3, b=3  has 1 tie    ties = n-a-b; reserve | from end. when a=b, use X.
        // |  X   X   X
        // . . . . . . .
        //
        // . . . . . . . a=4, b=1  has 2 tie    ties = n-a-b; reserve | from end. when a=b, use X.
        // | |  \ \ \ \
        // . . . . . . .
        //
        // . . . . . . . 
        //  \ \ \ \ \ \   solves a=n-1, b=1
        // . . . . . . .

        if (a+b > n || a == 0 && b > 0 || b == 0 && a > 0) {
            cout << "NO" << endl;
            continue;
        }

        vector<array<int, 2>> res;
        int ties = n-a-b;
        int pairs = a > 0 && b > 0 ? a == b ? a : min(a, b) - 1 : 0;
        a -= pairs;
        b -= pairs;
        if (a > b) {
            for (int i = 1; i <= a; ++i) {
                res.push_back({i+1, i});
            }
            res.push_back({1, a+1});
        }
        if (b > a) {
            for (int i = 1; i <= b; ++i) {
                res.push_back({i, i+1});
            }
            res.push_back({b+1, 1});
        }
        for (int i = 1; i <= ties; ++i) {
            res.push_back({a+b+i, a+b+i});
        }
        for (int i = 1; i <= pairs*2; i += 2) {
            res.push_back({a+b+ties+i, a+b+ties+i+1});
            res.push_back({a+b+ties+i+1, a+b+ties+i});
        }
        
        cout << "YES" << endl;
        for (int p = 0; p < 2; ++p) {
            for (int i = 0; i < n; ++i) {
                cout << res[i][p] << ' ';
            }
            cout << endl;
        }
    }
}