#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int N, idx[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a; --a;
        idx[a] = i;
    }
    int res = 1;
    for (int a = 0; a+1 < N; ++a) {
        res += idx[a] > idx[a+1];
    }
    cout << res << endl;
}