#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int L, N, J, B, X[MAXN], A[MAXN];
stack<int> S;

int main() {
    cin >> L >> N >> J >> B;
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> A[i];
    }
    // Always better to get farther ice cream if it is sweeter
    for (int i = N-1; i >= 0; --i) {
        if (S.size() && A[i] <= A[S.top()]) continue;
        S.push(i);
    }
    int x = 0;
    long long res = 0;
    while (S.size()) {
        int i = S.top();
        S.pop();
        res += (long long) (J-B)*(X[i]-x)*A[i];
        x = X[i];
    }
    cout << res << endl;
}