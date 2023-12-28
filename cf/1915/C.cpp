#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define ll long long

int NT, N, A[MAXN];

int main() {
    cin >> NT;
    while (NT--) {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> A[i];
        ll cur = 0;
        for (int i = 0; i < N; ++i) cur += A[i];
        ll s = roundl(sqrtl(cur));
        cout << (s*s == cur ? "YES" : "NO") << endl;
    }
}