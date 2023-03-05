#include <bits/stdc++.h>
using namespace std;

struct Part {
    int f, m, i;
};
bool cmp(Part &a, Part &b) {
    return a.f*b.m > b.f*a.m;
}
int main() {
    int F, M, N; cin >> F >> M >> N;
    Part A[N];
    for (int i = 0; i < N; ++i) {
        int f, m; cin >> f >> m;
        A[i] = {f, m, i+1};
    }
    sort(A, A+N, cmp);
    int res[N], cnt = 0;
    for (Part &p: A) {
        if (M*(F+p.f) <= F*(M+p.m)) continue;
        F += p.f;
        M += p.m;
        res[cnt] = p.i;
        ++cnt;
    }
    if (!cnt) cout << "NONE" << endl;
    sort(res, res+cnt);
    for (int i = 0; i < cnt; ++i) {
        cout << res[i] << endl;
    }
}