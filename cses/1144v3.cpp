#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
using ll = long long;

template<int...>
struct BIT {
    int v = 0;
    void update(int v) { this->v += v; }
    ll query() { return v; }
};

template<int N, int... Ns>
struct BIT<N, Ns...> {
    BIT<Ns...> bit[N];
    template<class... Ts>
    void update(int i, Ts... args) {
        for (; i < N; i |= i+1) bit[i].update(args...);
    }
    template<class... Ts>
    ll query(int l, int r, Ts... args) {
        ll res = 0;
        for (; r; r &= r-1) res += bit[r-1].query(args...);
        for (; l; l &= l-1) res -= bit[l-1].query(args...);
        return res;
    }
};

const int MAXN = 2e5+5;
int N, M;
int A[MAXN];
vector<array<int, 3>> Q;
vector<int> C;
BIT<2*MAXN> T;

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
        cout << T.query(lb(a), lb(b+1)) << endl;
    }
}