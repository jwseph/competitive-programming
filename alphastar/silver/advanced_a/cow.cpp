#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N;
ll C = 0, O = 0, W = 0;

int main() {
    cin >> N;
    while (N--) {
        char X; cin >> X;
        if (X == 'C') ++C;
        if (X == 'O') O += C;
        if (X == 'W') W += O;
    }
    cout << W << endl;
}