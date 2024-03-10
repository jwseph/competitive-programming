#include <bits/stdc++.h>
using namespace std;

int N, cnt[26];
string S, cur;
vector<string> res;

void sol(int i) {
    if (i == N) {
        res.push_back(cur);
        return;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (!cnt[c-'a']) continue;
        cnt[c-'a']--;
        cur += c;
        sol(i+1);
        cnt[c-'a']++;
        cur.pop_back();
    }
}

int main() {
    cin >> S;
    N = S.size();
    for (char c: S) cnt[c-'a']++;
    sol(0);
    cout << res.size() << endl;
    for (string r: res) cout << r << endl;
}