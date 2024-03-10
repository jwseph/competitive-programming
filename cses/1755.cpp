#include <bits/stdc++.h>
using namespace std;

int cnt[128];
string S, R;

int main() {
    cin >> S;
    for (char c: S) {
        ++cnt[c];
    }
    char odd = ' ';
    for (char c = 'A'; c <= 'Z'; ++c) {
        R += string(cnt[c]/2, c);
        if (cnt[c]%2 == 0) continue;
        if (odd != ' ') {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
        odd = c;
    }
    if (odd != ' ') R += odd;
    for (char c = 'Z'; c >= 'A'; --c) {
        R += string(cnt[c]/2, c);
    }
    cout << R << endl;
}