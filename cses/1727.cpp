#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k;

double sol(double i, double c) {
    return pow((c-1)/k, i) * pow(c/k, n-1-i) / k;
}

int main() {
    cin >> n >> k;
    double res = 0;
    for (int i = 0; i < n; ++i) {
        for (int c = 1; c <= k; ++c) {
            res += c*sol(i, c);
        }
    }
    cout << fixed << setprecision(6) << res << endl;
}