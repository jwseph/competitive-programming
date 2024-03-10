#include <bits/stdc++.h>
using namespace std;

int N;
set<int> S;
queue<int> Q;

int main() {
    cin >> N;
    int res = 0;
    while (N--) {
        int a; cin >> a;
        while (S.count(a)) {
            S.erase(Q.front());
            Q.pop();
        }
        S.insert(a);
        Q.push(a);
        res = max<int>(res, S.size());
    }
    cout << res << endl;
}