#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+6;

int n, cnt['Z'+1], inv[N], max_cnt = 0;
string s;

void insert(char c) {
    inv[cnt[c]]--;
    cnt[c]++;
    inv[cnt[c]]++;
    max_cnt = max(max_cnt, cnt[c]);
}

void erase(char c) {
    inv[cnt[c]]--;
    cnt[c]--;
    inv[cnt[c]]++;
    if (inv[max_cnt] == 0) {
        max_cnt--;
    }
}

int main() {
    inv[0] = 26;
    cin >> s; n = s.size();
    for (char c: s) {
        insert(c);
    }
    string res;
    for (int i = 0; i < n; ++i) {
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (!cnt[c]) continue;
            if (res.size() && res.back() == c) continue;
            erase(c);
            int rem = n-1-i;
            if (max_cnt > (rem+1)/2) {
                insert(c);
                continue;
            }
            res.push_back(c);
            break;
        }
        if (res.size() == i) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << res << endl;
}