#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int N, A[MAXN];
stack<int> S;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    A[0] = INT_MIN;
    S.push(0);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        while (A[i] <= A[S.top()]) S.pop();
        cout << S.top() << ' ';
        S.push(i);
    }
    cout << endl;
}