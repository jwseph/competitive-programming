#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define ll long long

int N, K, IN[MAXN]{};
ll H[MAXN];
bool V[MAXN]{};
set<int> A[MAXN];
vector<pair<int, ll>> A2[MAXN];
queue<int> Q;
vector<tuple<int, int, ll>> res;

int main() {
    cin >> N;
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        sum += H[i];
    }
    K = sum / N;
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j; --i; --j;
        A[i].insert(j);
        A[j].insert(i);
    }
    for (int i = 0; i < N; ++i) {
        if (A[i].size() != 1) continue;
        V[i] = 1;
        Q.push(i);
    }
    while (Q.size()) {
        int i = Q.front();
        Q.pop();
        auto adj = A[i];
        for (int j: adj) {
            A[i].erase(j);
            A[j].erase(i);
            if (H[i] > K) {
                ll car = H[i]-K;
                H[i] -= car;
                H[j] += car;
                A2[i].push_back({j, car});
                ++IN[j];
            }
            if (H[i] < K) {
                ll car = K-H[i];
                H[j] -= car;
                H[i] += car;
                A2[j].push_back({i, car});
                ++IN[i];
            }
            if (A[j].size() == 1 && !V[j]) {
                Q.push(j);
                V[j] = 1;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (IN[i] != 0) continue;
        Q.push(i);
    }
    while (Q.size()) {
        int i = Q.front();
        Q.pop();
        for (auto [j, w]: A2[i]) {
            res.push_back({i+1, j+1, w});
            if (--IN[j] == 0) {
                Q.push(j);
            }
        }
    }
    cout << res.size() << endl;
    for (auto [a, b, c]: res) cout << a << ' ' << b << ' ' << c << endl;
}