#include <bits/stdc++.h>
using namespace std;

int N;

int sol(int l, int r) {
    if (l == r) return 0;
    if (l+1 == r) return l*r;
    int h = (l+r)/2;
    return sol(l, h) + sol(h+1, r);
}

int main() {
    cin >> N;
    cout << sol(1, N) << endl;
}