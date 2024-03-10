#include <bits/stdc++.h>
using namespace std;

int N;
multiset<int> S;

int main() {
    cin >> N;
    while (N--) {
        int a; cin >> a;
        auto it = S.upper_bound(a);
        if (it != S.end()) {
            S.erase(it);
        }
        S.insert(a);
    }
    cout << S.size() << endl;
}