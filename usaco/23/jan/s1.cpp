#include <bits/stdc++.h>
using namespace std;

int NT, res;
string A, B;
unordered_map<char, int> V;
unordered_map<char, char> T;
unordered_map<char, int> IN;

bool dfs(char i) {
    if (V[i] == 2) return 0;
    if (V[i] == 1) {
        V[i] = 2;
        return 1;
    }
    V[i] = 1;
    if (T.find(i) == T.end()) {
        V[i] = 2;
        return 0;
    }
    char j = T[i];
    if (i == j) {
        V[i] = 2;
        res -= 1;
        return 0;
    }
    bool res = dfs(j);
    V[i] = 2;
    if (IN[j] > 1) return 0;
    return res;
}

int sol() {
    T = {};
    IN = {};
    V = {};
    for (int i = 0; i < A.size(); ++i) {
        char a = A[i], b = B[i];
        if (T.find(a) != T.end()) {
            if (T[a] != b) return -1;
            continue;
        }
        T[a] = b;
        ++IN[b];
    }
    bool cancycle = IN.size() < 52;
    res = 0;
    for (auto [a, b]: T) {
        if (dfs(a)) {
            if (!cancycle) return -1;
            ++res;
        }
    }
    res += T.size();
    return res;
}

int main() {
    cin >> NT;
    while (NT--) {
        cin >> A >> B;
        cout << sol() << endl;
    }
}