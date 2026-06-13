#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int nt; cin >> nt;
    while (nt--) {
        int qt, n; cin >> qt >> n;
        vector<int> pool;
        for (int i = 1; i <= n; ++i) {
            pool.push_back(i);
        }
        if (qt == 1) {
            ll k; cin >> k;
            k -= 1;
            vector<int> digits;
            for (int i = 1; i <= n; ++i) {
                digits.push_back(k%i);
                k /= i;
            }
            while (digits.size()) {
                int i = digits.back(); digits.pop_back();
                cout << pool[i] << ' ';
                pool.erase(pool.begin()+i);
            }
            cout << endl;
            continue;
        }
        ll res = 0;
        for (int s = n; s >= 1; --s) {
            int x; cin >> x;
            int i = find(begin(pool), end(pool), x) - begin(pool);
            pool.erase(pool.begin()+i);
            res *= s;
            res += i;
        }
        cout << res+1 << endl;
    }
}