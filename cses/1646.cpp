#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2e5+5;
int N, Q;
ll P[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        cin >> P[i+1];
        P[i+1] += P[i];
    }
    while (Q--) {
        int l, r; cin >> l >> r; --l;
        cout << P[r]-P[l] << endl;
    }
}