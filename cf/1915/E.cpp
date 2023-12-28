#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define ll long long

int NT, N;
int A[MAXN];
ll P[MAXN];
unordered_set<ll> V;

int main() {
    cin >> NT;
    while (NT--) {
        V = {};
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> A[i];
        P[0] = 0;
        for (int i = 0; i < N; ++i) {
            P[i+1] = P[i] + (i%2 == 0 ? 1 : -1) * A[i];
        }
        bool res = 0;
        for (int i = N-1; i >= 0; --i) {
            int cur = (i%2 == 0 ? 1 : -1) * A[i];
            V.insert(P[i+1]);
            res |= V.find(P[i+1]-cur) != V.end();
        }
        cout << (res ? "YES" : "NO") << endl;
    }
}