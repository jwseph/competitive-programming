#include <bits/stdc++.h>
using namespace std;

int M, T, U, F, D;

int main() {
    cin >> M >> T >> U >> F >> D;
    int i;
    for (i = 0; i < T; ++i) {
        char S; cin >> S;
        M -= S == 'f' ? 2*F : U+D;
        if (M < 0) break;
    }
    cout << i << endl;
}