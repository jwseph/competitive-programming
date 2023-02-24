// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=205

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int N, M, A = 0, B = 0, res = 0;
queue<pair<int, int>> P, Q;  // {time, dx}

int main() {
    cin >> N >> M;
    while (N--) {
        int X; char C; cin >> X >> C;
        P.push({X, C == 'L' ? -1 : 1});
    }
    while (M--) {
        int X; char C; cin >> X >> C;
        Q.push({X, C == 'L' ? -1 : 1});
    }
    while (!P.empty() && !Q.empty()) {
        int t = min(P.front().first, Q.front().first);
        int dif = A-B;
        bool pre = A != B && (A < B) != (P.front().second < Q.front().second);
        A += t * P.front().second;
        B += t * Q.front().second;
        if (pre && (dif < 0 && A-B >= 0 || dif > 0 && A-B <= 0)) {
            ++res;
        }
        if ((P.front().first -= t) == 0) P.pop();
        if ((Q.front().first -= t) == 0) Q.pop();
    }
    if (P.empty()) {
        swap(P, Q);
        swap(A, B);
    }
    while (!P.empty()) {
        bool pre = A != B;
        int dif = A-B;
        A += P.front().first * P.front().second;
        P.pop();
        if (pre && (dif < 0 && A-B >= 0 || dif > 0 && A-B <= 0)) {
            ++res;
        }
    }
    cout << res << endl;
}