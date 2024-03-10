#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll sol(ll i) {
    if (i == 1) return 0;
    if (i == 2) return 6;
    if (i == 3) return 28;
    int n = i*i-1;
    return (4*(n-2 + 2*(n-3) + n-4 + (i-4)*(n-4 + n-6)) + (i-4)*(i-4)*(n-8))/2;
}

int main() {
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) {
        cout << sol(i) << endl;
    }
}