#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n;
vector<int> ad[N];
int sz[N];

int dfs(int i, int p = -1) {
    int res = i;
    sz[i] = 1;
    for (int j: ad[i]) {
        if (j == p) continue;
        int k = dfs(j, i);
        if (sz[j] > n/2) res = k;
        sz[i] += sz[j];
    }
    return res;
}

int main() {
    cin >> n;
    for (int e = 0; e < n-1; ++e) {
        int i, j; cin >> i >> j;
        ad[i].push_back(j), ad[j].push_back(i);
    }
    cout << dfs(1) << endl;
}