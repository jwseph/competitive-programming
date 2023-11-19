#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> S;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int cur; cin >> cur >> cur;
        while (S.size() && S.top() > cur) S.pop();
        S.push(cur);
    }
    cout << S.size() << endl;
}