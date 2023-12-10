#include <bits/stdc++.h>
using namespace std;

#define MAXN 9

int N = MAXN;
queue<int> Q;
unordered_map<int, pair<int, int>> V;
int A[MAXN] = {
    0b000000000000001001000001001,
    0b000000000000000000001001001,
    0b000000000001001000001001000,
    0b000000001000000001000000001,
    0b000001000001001001000001000,
    0b001000000001000000001000000,
    0b000001001000001001000000000,
    0b001001001000000000000000000,
    0b001001000001001000000000000,
};
int keep = 0b011011011011011011011011011;

int main() {
    int start = 0;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        start |= t/3%4 << 3*i;
    }
    V[start] = {-1, -1};
    Q.push(start);
    while (Q.size()) {
        int i = Q.front();
        Q.pop();
        if (i == 0) {
            vector<int> res;
            while (V[i].first != -1) {
                res.push_back(V[i].second);
                i = V[i].first;
            }
            reverse(begin(res), end(res));
            for (int r: res) cout << r << ' ';
            cout << endl;
            return 0;
        }
        for (int s = 0; s < N; ++s) {
            int j = i+A[s] & keep;
            if (V.find(j) != V.end()) continue;
            V[j] = {i, s+1};
            Q.push(j);
        }
    }
    cout << -1 << endl;
}