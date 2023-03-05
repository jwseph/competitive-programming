#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> L, R[30];

int main() {
    cin >> N;
    char C;
    while (cin >> C) {
        int X; cin >> X;
        if (C == 'C') {
            L.push(X);
        }
        if (C == 'R') {
            R[X-1].push(L.front());
            L.pop();
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << R[i].size() << ' ';
        while (!R[i].empty()) {
            cout << R[i].front() << ' ';
            R[i].pop();
        }
        cout << endl;
    }
}