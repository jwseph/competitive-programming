#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    cin >> N;
    long long res = 0;
    int cur = INT_MIN;
    while (N--) {
        int a; cin >> a;
        cur = max(cur, a);
        res += cur-a;
    }
    cout << res << endl;
}