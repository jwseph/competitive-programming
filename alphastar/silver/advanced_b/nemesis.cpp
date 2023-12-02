#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int N, M;
vector<int> A[MAXN];
queue<int> Q;
bool V[MAXN]{};

int main() {
    cin >> N >> M;
    while (M--) {
        int i, j; cin >> i >> j; --i; --j;
        A[i].push_back(j);
        A[j].push_back(i);
    }
    Q.push(0);
    V[0] = 1;
    int res_i = 1, res_len = 0, res_cnt = 1;
    for (int cur = 0; Q.size(); ++cur) {
        res_i = INT_MAX;
        res_len = cur;
        res_cnt = Q.size();
        for (int qs = Q.size(); qs > 0; --qs) {
            int i = Q.front();
            Q.pop();
            res_i = min(res_i, i+1);
            for (int j: A[i]) {
                if (V[j]) continue;
                V[j] = 1;
                Q.push(j);
            }
        }
    }
    cout << res_i << ' ' << res_len << ' ' << res_cnt << endl;
}