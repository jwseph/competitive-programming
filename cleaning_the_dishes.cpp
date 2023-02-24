#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> S[3];

int main() {
    cin >> N;
    for (int i = N; i >= 1; --i) {
        S[0].push(i);
    }
    int C, D;
    while (cin >> C) {
        cin >> D;
        while (D--) {
            S[C].push(S[C-1].top());
            S[C-1].pop();
        }
    }
    while (!S[2].empty()) {
        cout << S[2].top() << endl;
        S[2].pop();
    }
}