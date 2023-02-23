#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> S, T;

int main() {
    cin >> N;
    int cnt = 0;
    while (N--) {
        string s; cin >> s;
        if (s == "ADD") S.push(++cnt);
        else if (s == "REMOVE") S.pop();
        else cout << "Error" << endl;
    }
    cout << S.size() << endl;
    while (!S.empty()) {
        T.push(S.top());
        S.pop();
    }
    while (!T.empty()) {
        cout << T.top() << endl;
        T.pop();
    }
}