#include <bits/stdc++.h>
using namespace std;

using ld = __float128;

const int K = 102;
int n;
ld pb[K];

void print_rounded(ld res) {
    int w = 1e6;
    ld scaled = res*w;
    long long int_part = scaled;
    ld rem = scaled-int_part;

    if (rem > 0.5 + 7e-17) {
        int_part++;
    } else if (rem > 0.5 - 7e-17) {
        int_part += int_part%2;
    }

    cout << int_part/w << "." << setfill('0') << setw(6) << int_part%w << endl;
}

int main() {
    cin >> n;
    ld res = 0;
    while (n--) {
        int a; cin >> a;
        for (int k = 1; k <= a; ++k) {
            res += pb[k]/a;
            pb[k] += ((ld)a-k)/a;
        }
    }
    print_rounded(res);
    // cout << fixed << setprecision(6) << (long double)res << endl;
}