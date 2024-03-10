#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> res;

void sol(int n, int f, int t, int h) {
    if (!n) return;
    sol(n-1, f, h, t);
    res.push_back({f, t});
    sol(n-1, h, t, f);
}

int main() {
    cin >> N;
    sol(N, 1, 3, 2);
    cout << res.size() << endl;
    for (auto [a, b]: res) cout << a << ' ' << b << endl;
}