#include <bits/stdc++.h>
using namespace std;

#define MAXN 1003

int NT, N, NF, P[MAXN], P2[MAXN];
vector<int> A[MAXN], A2[MAXN];
bool V[MAXN];
vector<pair<int, int>> res;
queue<int> Q;

void merge(int i, int j) {
    // P[i] == P[j]
    if (P[i] != P[j]) {
        merge(P[i], P[j]);
    }
    if (i < j) swap(i, j);
    res.push_back({j, i});
    V[j] = 0;
    for (int k: A[j]) {
        P[k] = i;
        A[i].push_back(k);
    }
    A[j] = {};
    int p = P[i];
    A[p].erase(find(A[p].begin(), A[p].end(), j));
}
void eliminate(int s) {
    vector<int> v;
    int p = P[s];
    v.push_back(p);
    v.push_back(s);
    for (int i = s; A[i].size(); i = A[i][0]) {
        auto adj = A[i];
        auto it = max_element(begin(adj), end(adj));
        int j = *it;
        adj.erase(it);
        for (int k: adj) {
            merge(j, k);
        }
        v.push_back(j);
    }
    queue<int> q;
    q.push(p);
    for (int level = 0; q.size(); ++level) {
        for (int qs = q.size(); qs > 0; --qs) {
            int i = q.front(); q.pop();
            if (i < v[level]) continue;
            if (level == v.size()-1) {
                merge(i, v[level]);
                return;
            }
            for (int j: A2[i]) q.push(j);
        }
    }
}

int main() {
    cin >> NT;
    while (NT--) {

        cin >> N;
        res = {};
        Q = {};
        for (int i = 0; i < N; ++i) {
            P[i] = -1;
            V[i] = 0;
            A[i] = {};
            P2[i] = -1;
            A2[i] = {};
        }

        for (int e = 0; e < N-1; ++e) {
            int i, p; cin >> i >> p; --i; --p;
            P[i] = p;
            A[p].push_back(i);
            V[i] = 1;
        }
        int s;
        for (int i = 0; i < N; ++i) {
            if (!V[i]) s = i;
        }
        cin >> NF;
        for (int e = 0; e < NF-1; ++e) {
            int i, p; cin >> i >> p; --i; --p;
            P2[i] = p;
            A2[p].push_back(i);
            V[i] = 0;
            if (P[i] != p) merge(P[i], p);
        }

        Q.push(s);
        while (Q.size()) {
            int i = Q.front(); Q.pop();
            if (P[i] >= 0 && P2[i] < 0) {
                eliminate(i);
                continue;
            }
            for (int j: A[i]) {
                Q.push(j);
            }
        }
        cout << res.size() << endl;
        for (auto [i, j]: res) {
            cout << i+1 << ' ' << j+1 << endl;
        }

    }
}