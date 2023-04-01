#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    cin >> N;
    int candy = 0, res = N;
    for (int i = 0, j = 0, pay = 0; i < N; ++i) {
        int D; cin >> D;
        if (D >= 0) candy += D;
        else {
            if (!pay) j = i;
            pay -= D;
        }
        if (pay && candy >= pay) {
            candy -= pay;
            res += 2*(i-j);
            pay = 0;
        }
    }
    cout << res << endl;
}