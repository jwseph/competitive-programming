#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N; cin >> N;
    while (N > 1) {
        cout << N << ' ';
        N = N&1 ? N*3+1 : N/2;
    }
    cout << 1 << endl;
}