#include <bits/stdc++.h>
using namespace std;

int sol(string S, int B) {
    int N = 0;
    for (char& C: S) {
        N = N*B + C-'0';
    }
    return N;
}

int main() {
    string A, B; cin >> A >> B;
    unordered_set<int> pos;
    for (char& C: A) {
        char og = C;
        for (C = '0'; C <= '1'; ++C) {
            pos.insert(sol(A, 2));
        }
        C = og;
    }
    for (char& C: B) {
        char og = C;
        for (C = '0'; C <= '2'; ++C) {
            int N = sol(B, 3);
            if (pos.count(N)) {
                cout << N << endl;
                return 0;
            }
        }
        C = og;
    }
    cout << -1 << endl;
}