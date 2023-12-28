#include <bits/stdc++.h>
using namespace std;

int NT, N;
string S;

int main() {
    cin >> NT;
    while (NT--) {
        cin >> N >> S;
        vector<string> V;
        bool vowlast = 0;
        string cur;
        for (int i = N-1; i >= 0; --i) {
            if (S[i] == 'b' || S[i] == 'c' || S[i] == 'd') {
                if (vowlast) {
                    cur += S[i];
                    V.push_back(cur);
                    cur = "";
                    vowlast = 0;
                    continue;
                }
                vowlast = 0;
                V.push_back(cur);
                cur = "";
                cur += S[i];
                continue;
            }
            cur += S[i];
            vowlast = 1;
        }
        string res;
        reverse(begin(V), end(V));
        for (string& T: V) {
            if (T.empty()) continue;
            reverse(begin(T), end(T));
            res += T;
            res += '.';
        }
        res.pop_back();
        cout << res << endl;
    }
}