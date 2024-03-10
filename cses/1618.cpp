#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll N, res = 0;

int main() {
    cin >> N;
    for (ll i = 5; i <= N; i *= 5) res += N/i;
    cout << res << endl;
}