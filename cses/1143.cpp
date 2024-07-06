#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+5;
int N, M;

int T[2*MAXN];
void update(int i, int v) {
    for (T[i += N] = v; i /= 2;) T[i] = max(T[i*2], T[i*2+1]);
}
int lower(int v) {
    if (T[1] < v) return N;
    int i = 1;
    while (i < N) {
        i = T[i*2] >= v ? i*2 : i*2+1;
    }
    return i-N;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n >> M;
    N = 1;
    while (N < n) N *= 2;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        update(i, v);
    }
    while (M--) {
        int v; cin >> v;
        int i = lower(v);
        if (i == N) {
            cout << 0 << ' ';
            continue;
        }
        cout << i+1 << ' ';
        update(i, T[i+N]-v);
    }
    cout << endl;
}