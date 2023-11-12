#include <bits/stdc++.h>
using namespace std;

#define MAXN 25000

string S1, S2, S;
unordered_set<string> U;
queue<string> Q;

int main() {
    cin >> S1 >> S2;
    while (cin >> S) {
        if (S.size() != S1.size()) continue;
        U.insert(S);
    }
    U.erase(S1);
    Q.push(S1);
    for (int res = 0; Q.size(); ++res) {
        for (int qs = Q.size(); qs > 0; --qs) {
            string i = Q.front();
            Q.pop();
            if (i == S2) {
                cout << res << endl;
                return 0;
            }
            for (int p = 0; p < i.size(); ++p) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    string j = i;
                    j[p] = c;
                    if (U.find(j) != U.end()) {
                        U.erase(j);
                        Q.push(j);
                    }
                }
            }
        }
    }
}