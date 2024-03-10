#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int N, M;
vector<int> A[MAXN];
int P[MAXN];
queue<int> Q;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j;
        A[i].push_back(j);
        A[j].push_back(i);
    }
    Q.push(1);
    P[1] = -1;
    while (Q.size()) {
        int i = Q.front();
        Q.pop();
        if (i == N) {
            vector<int> res;
            while (i != 1) {
                res.push_back(i);
                i = P[i];
            }
            res.push_back(1);
            reverse(begin(res), end(res));
            cout << res.size() << endl;
            for (int j: res) cout << j << ' ';
            cout << endl;
            return 0;
        }
        for (int j: A[i]) {
            if (P[j]) continue;
            P[j] = i;
            Q.push(j);
        }
    }
    cout << "IMPOSSIBLE" << endl;
}