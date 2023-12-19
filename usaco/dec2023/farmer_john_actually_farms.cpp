#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define ll long long

int NT, N, IDX[MAXN];
ll H[MAXN], G[MAXN], T[MAXN];

bool cmp(int i, int j) {
    return T[i] > T[j];
}

int sol() {
    int maxt = INT_MAX, mint = 0;
    for (int ii = 1; ii < N; ++ii) {
        int i = IDX[ii-1], j = IDX[ii];
        if (H[i] < H[j] && G[i] == G[j]) continue;
        if (H[i] >= H[j] && G[i] == G[j]) return -1;
        if (H[i] < H[j]) {
            if (G[i] < G[j]) continue;
            int h = H[j]-H[i], g = G[i]-G[j];
            maxt = min(maxt, (h+g-1)/g-1);
        }
        if (H[i] > H[j]) {
            if (G[i] > G[j]) return -1;
            int h = H[i]-H[j], g = G[j]-G[i];
            mint = max(mint, h/g+1);
        }
    }
    int t = mint;
    for (int ii = 1; ii < N; ++ii) {
        int i = IDX[ii-1], j = IDX[ii];
        if (H[i]+t*G[i] >= H[j]+t*G[j]) return -1;
    }
    return t;
}

int main() {
    cin >> NT;
    while (NT--) {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> H[i];
        for (int i = 0; i < N; ++i) cin >> G[i];
        for (int i = 0; i < N; ++i) cin >> T[i];
        for (int i = 0; i < N; ++i) IDX[i] = i;
        sort(IDX, IDX+N, cmp);
        cout << sol() << endl;
    }
}