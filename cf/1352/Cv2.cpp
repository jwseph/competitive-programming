#include <bits/stdc++.h>
using namespace std;

int NT, N, K;

int sol(int h) {
    int res = h-h/N-1;
    return res;
}

int main() {
    cin >> NT;
    while (NT--) {
        cin >> N >> K; --K;
        int l = 1, r = 2*(K+1);
        while (l < r) {
            int h = l+(r-l)/2;
            if (K <= sol(h)) r = h;
            else l = h+1;
        }
        cout << l << endl;
    }
}