#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000006

int N, A[MAXN]{};
string res;

void sol(int l) {
    int r = l;
    while (A[r]) {
        A[r] -= 2;
        ++r;
        res += 'R';
    }
    bool car = 0;
    for (int i = r; i > l; --i) {
        if (i-1 >= l && A[i-1]) {
            car = 1;
            res += 'L';
            continue;
        }
        if (car) {
            car = 0;
            sol(i);
        }
        res += 'L';
    }
    if (car) {
        car = 0;
        sol(l);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sol(0);
    cout << res << endl;
}