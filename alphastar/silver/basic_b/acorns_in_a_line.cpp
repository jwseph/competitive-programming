#include <bits/stdc++.h>
using namespace std;

int N, A[1<<10], res = 0;

void ms(int l, int r) {
    if (r-l <= 1) return;
    int h = (l+r)/2;
    ms(l, h);
    ms(h, r);
    if (A[l] <= A[h]) return;
    for (int i = l; i < h; ++i) {
        swap(A[i], A[i+h-l]);
    }
    res += (r-l)*(h-l);
}

int main() {
    cin >> N;
    N = 1<<N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    ms(0, N);
    cout << res << endl;
    for (int i = 0; i < N; ++i) {
        cout << A[i] << endl;
    }
}