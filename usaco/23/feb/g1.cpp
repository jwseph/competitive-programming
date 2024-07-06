#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vr vector
#define pb push_back
#define all(v) begin(v), end(v)

#define MAXN 502

int N;
ll P[MAXN];
vr<tuple<ll, int, int>> S;

int main() {
    // Two pointer is still better than binary search
    cin >> N;
    P[0] = 0;
    for (int i = 0; i < N; ++i) {
        cin >> P[i+1];
        P[i+1] += P[i];
    }
    for (int l = 0; l <= N; ++l) {
        for (int r = l+1; r <= N; ++r) {
            S.pb({P[r]-P[l], l, r});
        }
    }
    sort(all(S));
    for (int h = 0; h < N; ++h) {
        queue<ll> A, B;
        for (auto [s, l, r]: S) {
            if (l <= h && h < r) {
                B.push(s);
                continue;
            }
            A.push(s);
        }
        ll res = LLONG_MAX;
        while (A.size() && B.size()) {
            res = min(res, abs(A.front()-B.front()));
            (A.front() < B.front() ? A : B).pop();
        }
        cout << res << endl;
    }
}