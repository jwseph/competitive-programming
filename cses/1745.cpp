#include <bits/stdc++.h>
using namespace std;

int N;
set<int> S;

int main() {
    cin >> N;
    S.insert(0);
    while (N--) {
        int a; cin >> a;
        for (int v: vector<int>(begin(S), end(S))) {
            S.insert(v+a);
        }
    }
    S.erase(0);
    cout << S.size() << endl;
    for (int v: S) cout << v << ' ';
    cout << endl;
}