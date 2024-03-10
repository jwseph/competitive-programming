#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<>> Q;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) Q.push(i);
    while (Q.size()) {
        Q.push(Q.top()+N);
        Q.pop();
        cout << Q.top()%N + 1 << ' ';
        Q.pop();
    }
    cout << endl;
}