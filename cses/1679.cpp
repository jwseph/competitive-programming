#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int N, M, in[MAXN];
vector<int> A[MAXN];
queue<int> Q;

int main() {
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j; --i; --j;
        in[j]++;
        A[i].push_back(j);
    }
    for (int i = 0; i < N; ++i) {
        if (!in[i]) Q.push(i);
    }
    vector<int> res;
    while (Q.size()) {
        int i = Q.front(); Q.pop();
        res.push_back(i+1);
        for (int j: A[i]) {
            if (!in[j]) continue;
            --in[j];
            if (!in[j]) Q.push(j);
        }
    }
    if (res.size() < N) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int a: res) cout << a << ' ';
    cout << endl;
}