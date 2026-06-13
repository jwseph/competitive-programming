#include <bits/stdc++.h>
using namespace std;

set<int> s;
int cnt[202], arr[102][102];

void insert(int x) {
    cnt[x]++;
    s.erase(x);
}

void erase(int x) {
    if (--cnt[x] == 0) {
        s.insert(x);
    }
}

int mex() {
    return *s.begin();
}

int main() {
    for (int i = 0; i < 202; ++i) {
        s.insert(i);
    }
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < i; ++k) {
                insert(arr[k][j]);
            }
            insert(arr[i][j] = mex());
            cout << arr[i][j] << ' ';
            for (int k = 0; k < i; ++k) {
                erase(arr[k][j]);
            }
        }
        cout << endl;
        for (int j = 0; j < n; ++j) {
            erase(arr[i][j]);
        }
    }
}