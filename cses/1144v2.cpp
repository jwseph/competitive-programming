#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

struct BIT {
    vector<int> t; int n;
    BIT(int n): t(n), n(n) {}
    void update(int i, int v) {
        for (; i < n; i |= i+1) t[i] += v;
    }
    int query(int i) {
        int res = 0;
        for (; i; i &= i-1) res += t[i-1];
        return res;
    }
};

const int MAXN = 2e5+5;
int N, M;
int A[MAXN];
vector<array<int, 3>> Q;
vector<int> C;
BIT T(0);

int lb(int a) {
    return lower_bound(all(C), a) - begin(C);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        C.push_back(A[i]);
    }
    for (int q = 0; q < M; ++q) {
        char t; int a, b; cin >> t >> a >> b;
        Q.push_back({t, a, b});
        if (t == '!') {
            C.push_back(b);
        }
    }
    sort(all(C));
    C.erase(unique(all(C)), end(C));
    T = BIT(C.size());
    for (int i = 0; i < N; ++i) {
        T.update(lb(A[i]), 1);
    }
    for (auto [t, a, b]: Q) {
        if (t == '!') {
            int i = a-1;
            T.update(lb(A[i]), -1);
            A[i] = b;
            T.update(lb(A[i]), 1);
            continue;
        }
        cout << T.query(lb(b+1)) - T.query(lb(a)) << endl;
    }
}