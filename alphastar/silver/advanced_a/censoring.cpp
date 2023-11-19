#include <bits/stdc++.h>
using namespace std;

string S, T, res;

int main() {
    cin >> S >> T;
    for (char C: S) {
        res += C;
        if (res.size() >= T.size() && res.compare(res.size()-T.size(), T.size(), T) == 0) {
            res.erase(res.size()-T.size(), T.size());
        }
    }
    cout << res << endl;
}