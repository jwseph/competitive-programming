#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int N, X[MAXN], Y[MAXN], dx, dy, DX[MAXN], DY[MAXN];
string S;
set<pair<int, int>> R;

int main() {
    cin >> S;
    N = S.size();
    X[0] = Y[0] = 0;
    dy = 1, dx = 0;
    DX[0] = dx;
    DY[0] = dy;
    for (int i = 0; i < N; ++i) {
        X[i+1] = X[i];
        Y[i+1] = Y[i];
        if (S[i] == 'L') {
            swap(dx, dy);
            dy *= -1;
        }
        if (S[i] == 'R') {
            swap(dx, dy);
            dx *= -1;
        }
        if (S[i] == 'F') {
            X[i+1] += dx;
            Y[i+1] += dy;
        }
        DX[i+1] = dx;
        DY[i+1] = dy;
    }
    for (int i = 0; i < N; ++i) {
        int x = X[N]-X[i+1], y = Y[N]-Y[i+1];
        if (S[i] == 'L') {
            R.insert({X[i]-x, Y[i]-y});
            y *= -1;
            swap(x, y);
            R.insert({X[i]+x+DX[i], Y[i]+y+DY[i]});
        }
        if (S[i] == 'R') {
            R.insert({X[i]-x, Y[i]-y});
            x *= -1;
            swap(x, y);
            R.insert({X[i]+x+DX[i], Y[i]+y+DY[i]});
        }
        if (S[i] == 'F') {
            R.insert({X[i]+y, Y[i]-x});
            R.insert({X[i]-y, Y[i]+x});
        }
    }
    cout << R.size() << endl;
}