#include <bits/stdc++.h>
using namespace std;

int n, a[200005];
unordered_set<int> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long res = 0;
    for (int r = 0, l = 0; r < n; ++r) {
        while (v.count(a[r])) {
            v.erase(a[l++]);
        }
        v.insert(a[r]);
        res += v.size();
    }
    cout << res << endl;
}