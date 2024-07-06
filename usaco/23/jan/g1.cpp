#include <bits/stdc++.h>
using namespace std;

#define ll long long

string res;

struct Node {
    char c;  // current value
    ll sz;
    vector<Node*> adj;
    Node(char c, ll sz) {
        this->c = c;
        this->sz = sz;
    }
    int ci = -1, cj = -1;
    void sol(ll l, ll r) {
        if (!adj.size()) {
            res += c;
            return;
        }
        if (l == 0 && r == sz && cj >= 0) {
            for (int i = ci; i < cj; ++i) res += res[i];
            return;
        }
        if (l == 0 && r == sz) ci = res.size();

        int i = 0;
        while (i < adj.size() && adj[i]->sz <= l) {
            l -= adj[i]->sz;
            r -= adj[i]->sz;
            ++i;
        }
        int j = i;
        while (j < adj.size() && adj[j]->sz < r) {
            r -= adj[j]->sz;
            ++j;
        }
        for (; i < j; ++i) {
            adj[i]->sol(l, adj[i]->sz);
            l = 0;
        }
        adj[i]->sol(l, r);
        if (l == 0 && r == sz) cj = res.size();
    }
};

int N;
ll L, R;
Node* A[128];
vector<pair<char, string>> O;

int main() {
    cin >> L >> R >> N;
    for (char c = 'a'; c <= 'z'; ++c) A[c] = new Node(c, 1);
    O.resize(N);
    for (int i = 0; i < N; ++i) cin >> O[i].first >> O[i].second;
    reverse(begin(O), end(O));
    for (auto [s, t]: O) {
        Node* cur = new Node(s, 0);
        for (char c: t) {
            Node* nei = A[c];
            cur->sz = min<ll>(cur->sz + nei->sz, 1e18);
            cur->adj.push_back(nei);
        }
        A[s] = cur;
    }
    A['a']->sol(L-1, R);
    cout << res << endl;
}