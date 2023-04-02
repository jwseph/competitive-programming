#include <bits/stdc++.h>
using namespace std;

int K;
string ID;
set<string> names;

bool ok(const string& S) {
    if (S.size() != K) return false;
    for (int i = 0; i < K; ++i) {
        char D = S[i];
        if (D > 'Q') --D;
        D = (D-'A')/3+2+'0';
        if (D != ID[i]) return false;
    }
    return true;
}

int main() {
    cin >> ID;
    K = ID.size();
    string S;
    while (cin >> S) {
        names.insert(S);
    }
    bool none = 1;
    for (const string& S: names) {
        if (!ok(S)) continue;
        cout << S << endl;
        none = 0;
    }
    if (none) cout << "NONE" << endl;
}