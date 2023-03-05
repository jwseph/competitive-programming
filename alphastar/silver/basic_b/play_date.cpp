#include <bits/stdc++.h>
using namespace std;

#define N_MAX 1001

int N, Q;
vector<pair<int, int>> adj[N_MAX];  // {adj index, distance}

int dfs(int A, int B, int P) {
    if (A == B) return 0;
    for (auto &p: adj[A]) {
        if (p.first == P) continue;
        int cur = dfs(p.first, B, A);
        if (cur >= 0) {
            return cur+p.second;
        }
    }
    return -1;
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N-1; ++i) {
        int A, B, L; cin >> A >> B >> L;
        adj[A].push_back({B, L});
        adj[B].push_back({A, L});
    }
    while (Q--) {
        int A, B; cin >> A >> B;
        cout << dfs(A, B, -1) << endl;
    }
}