#include <bits/stdc++.h>
using namespace std;

#define MAX_Y 101

int X, Y, K, M, res = INT_MAX;
bool V[MAX_Y*MAX_Y];
queue<int> Q;

void add(int x, int y) {
    int i = x*MAX_Y+y;
    if (V[i]) return;
    V[i] = true;
    Q.push(i);
}

int main() {
    cin >> X >> Y >> K >> M;
    memset(V, 0, sizeof V);
    Q.push(0);
    V[0] = true;
    for (int i = 0; i <= K; ++i) {
        for (int s = Q.size(); s > 0; --s) {
            int x = Q.front()/MAX_Y, y = Q.front()%MAX_Y;
            Q.pop();
            int cur = abs(M-(x+y));
            res = min(res, cur);
            add(X, y);  // fill to top
            add(x, Y);
            add(0, y);  // empty pail
            add(x, 0);
            int dif = min(X-x, y);
            add(x+dif, y-dif);  // pour y to x
            dif = min(x, Y-y);
            add(x-dif, y+dif);
        }
    }
    cout << res << endl;
}