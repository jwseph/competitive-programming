#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

#define MAXN 100005

int N;
pii A[MAXN];
priority_queue<int, vector<int>, greater<>> Q;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A+N);
    for (int i = 0; i < N; ++i) {
        auto [a, b] = A[i];
        int c = b;
        while (Q.size() && Q.top() <= b) {
            c = min(c, Q.top());
            Q.pop();
        }
        Q.push(c);
    }
    cout << Q.size() << endl;
}