#include <bits/stdc++.h>
using namespace std;

#define MAXN 50'000
#define pii pair<int, int>

int N;
set<pii> X, Y;

int sol(int i);

int solxy(int x, int y, int i) {
    X.erase({x, y});
    Y.erase({y, x});
    int res = sol(i);
    X.insert({x, y});
    Y.insert({y, x});
    return res;
}

int sol(int i) {
    if (i == 3) {
        int w = X.rbegin()->first - X.begin()->first;
        int h = Y.rbegin()->first - Y.begin()->first;
        return w*h;
    }
    return min({
        solxy(X.begin()->first, X.begin()->second, i+1),
        solxy(X.rbegin()->first, X.rbegin()->second, i+1),
        solxy(Y.begin()->second, Y.begin()->first, i+1),
        solxy(Y.rbegin()->second, Y.rbegin()->first, i+1)
    });
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        X.insert({x, y});
        Y.insert({y, x});
    }
    cout << sol(0) << endl;
}