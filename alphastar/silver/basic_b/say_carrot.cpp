#include <bits/stdc++.h>
using namespace std;

int N;

int cnt(int X) {
    return X-X/3-X/5+X/15;
}

int main() {
    cin >> N;
    int l = 0, r = INT_MAX;
    while (l < r) {
        int h = l+(r-l)/2;
        if (N <= cnt(h)) r = h;
        else l = h+1;
    }
    cout << l << endl;
}