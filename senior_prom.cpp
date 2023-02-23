#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    cin >> N;
    while (N--) {
        int K; string S; cin >> K >> S;
        int d = 0;
        for (char& C: S) {
            if (C == '>') ++d;
            if (C == '<') {
                --d;
                if (d < 0) break;
            }
        }
        cout << (d == 0 ? "legal" : "illegal") << endl;
    }
}