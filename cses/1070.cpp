#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    cin >> N;
    if (N == 2 || N == 3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    for (int i = 2; i <= N; i += 2) cout << i << ' ';
    for (int i = 1; i <= N; i += 2) cout << i << ' ';
    cout << endl;
}