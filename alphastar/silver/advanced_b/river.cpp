#include <bits/stdc++.h>
using namespace std;

#define MAXK 128

int N;
vector<pair<char, int>> A[MAXK];

int sol() {
    queue<char> Q;
    pair<char, int> P[MAXK];
    bool V[MAXK]{};
    V['A'] = 1;
    Q.push('A');
    while (Q.size()) {
        char i = Q.front();
        Q.pop();
        for (int e = 0; e < A[i].size(); ++e) {
            auto [j, w] = A[i][e];
            if (V[j] || !w) continue;
            V[j] = 1;
            P[j] = {i, e};
            Q.push(j);
        }
    }
    if (!V['Z']) return 0;
    char i = 'Z';
    int flow = INT_MAX;
    while (i != 'A') {
        auto [j, e] = P[i];
        i = j;
        flow = min(flow, A[i][e].second);
    }
    i = 'Z';
    while (i != 'A') {
        auto [j, e] = P[i];
        i = j;
        A[i][e].second -= flow;
    }
    return flow;
}

int main() {
    cin >> N;
    while (N--) {
        char i, j; cin >> i >> j;
        int w; cin >> w;
        A[i].push_back({j, w});
    }
    int cur = 0, res = 0;
    while (cur = sol()) res += cur;
    cout << res << endl;
}