#include <bits/stdc++.h>
using namespace std;

#define MAXA 1000006

int N, cnt[MAXA]{};

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        ++cnt[a];
    }
    for (int i = MAXA-1; i; --i) {
        int cur = 0;
        for (int j = i; j < MAXA; j += i) {
            cur += cnt[j];
        }
        if (cur >= 2) {
            cout << i << ' ';
            return 0;
        }
    }
}