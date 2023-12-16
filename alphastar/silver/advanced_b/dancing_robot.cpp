#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> IDX = {{"FL", 0}, {"FR", 1}, {"RL", 2}, {"RR", 3}};
int X[4] = {0, 1, 0, 1}, Y[4] = {1, 1, 0, 0};
int N, dir = 0;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string D = "FRBL";

bool error() {
    for (int i = 0; i < 4; ++i) {
        for (int j = i+1; j < 4; ++j) {
            if (X[i] == X[j] && Y[i] == Y[j]) return 1;
        }
    }
    return 0;
}

int main() {
    cin >> N;
    int mx = 0, MX = 1, my = 0, MY = 1;
    while (N--) {
        char c1, c2, d; cin >> c1 >> c2 >> d;
        string S; S += c1; S += c2;
        int i = IDX[S];
        if (d != 'P') {
            int dd = D.find(d);
            X[i] += dx[(dir+dd)%4];
            Y[i] += dy[(dir+dd)%4];
        }
        if (d == 'P') {
            dir = (dir+1)%4;
            for (int j = 0; j < 4; ++j) {
                int x = X[j]-X[i], y = Y[j]-Y[i];
                X[j] = X[i]+y;
                Y[j] = Y[i]-x;
            }
        }
        for (int j = 0; j < 4; ++j) {
            mx = min(mx, X[j]);
            MX = max(MX, X[j]);
            my = min(my, Y[j]);
            MY = max(MY, Y[j]);
        }
        if (error()) break;
    }
    cout << (MX-mx+1) * (MY-my+1) << endl;
}