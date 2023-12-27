#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define MAXM 200005
#define ll long long

int N, M;
ll H[MAXN], L[MAXM]{}, R[MAXM];
queue<int> Q;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> H[i];
    for (int c = 0; c < M; ++c) {
        cin >> R[c];
        Q.push(c);
    }
    for (int i = 0; i < N; ++i) {
        for (int qs = Q.size(); qs > 0; --qs) {
            int c = Q.front();
            Q.pop();
            ll eat = max(0ll, min(H[i], R[c])-L[c]);
            L[c] += eat;
            H[i] += eat;
            if (L[c] < R[c]) Q.push(c);
        }
        cout << H[i] << endl;
    }
}