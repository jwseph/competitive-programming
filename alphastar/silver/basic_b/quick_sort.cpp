#include <bits/stdc++.h>
using namespace std;

int N, A[500];

void print() {
    for (int i = 0; i < N; ++i) {
        cout << A[i] << ' ';
    }
    cout << endl;
}

void qs(int l, int r) {
    if (r-l <= 1) return;
    int j = l;
    for (int i = l; i < r; ++i) {
        if (A[i] <= A[r-1]) {
            swap(A[i], A[j++]);
        }
    }
    print();
    qs(l, j-1);
    qs(j, r);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    qs(0, N);
    return 0;
}