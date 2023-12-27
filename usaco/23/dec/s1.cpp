#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define pii pair<int, int>
#define ll long long

int N, M, K;
pair<int, int> A[MAXN];
queue<pair<int, ll>> Q;

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) cin >> A[i].first >> A[i].second;
    sort(A, A+N);
    Q.push({INT_MIN, M});
    ll res = 0;
    for (int i = 0; i < N; ++i) {
        ll cur = 0;
        while (Q.size() && A[i].second && Q.front().first+K <= A[i].first) {
            ll car = min((ll)A[i].second, Q.front().second);
            res += car;
            A[i].second -= car;
            Q.front().second -= car;
            if (Q.front().second == 0) Q.pop();
            cur += car;
        }
        Q.push({A[i].first, cur});
    }
    cout << res << endl;
}