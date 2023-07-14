#include <bits/stdc++.h>
using namespace std;

#define MAXN 50'000

int N, X[MAXN], Y[MAXN];
unordered_set<int> x, y;

bool sol(int i) {
    if (i == N) return 1;
    if (x.count(X[i]) || y.count(Y[i])) return sol(i+1);
    if (x.size()+y.size() == 3) return 0;
    bool res = 0;
    x.insert(X[i]);
    res = sol(i+1);
    x.erase(X[i]);
    if (res) return 1;
    y.insert(Y[i]);
    res = sol(i+1);
    y.erase(Y[i]);
    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }
    cout << sol(0) << endl;
}