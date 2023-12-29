#include <bits/stdc++.h>
using namespace std;

#define MN 200005
#define vr vector
#define pii pair<int, int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ll long long

int NT, N, T[MN];
void update(int i, int v) {
    for (; i < N; i |= i+1) T[i] += v;
}
int query(int i) {
    int res = 0;
    for (; i; i &= i-1) res += T[i-1];
    return res;
}

int main() {
    cin >> NT;
    while (NT--) {
        cin >> N;
        vr<pii> A;
        for (int i = 0; i < N; ++i) {
            int a; cin >> a;
            A.pb({-a, i});
            T[i] = 0;
        }
        sort(all(A));
        ll res = 0;
        for (auto [a, i]: A) {
            res += query(i);
            update(i, 1);
        }
        cout << res << endl;
    }
}