#include <bits/stdc++.h>
using namespace std;

int N, A[500];

void print() {
    for (int i = 0; i < N; ++i) {
        cout << A[i] << ' ';
    }
    cout << endl;
}

queue<int> ms(int l, int r) {
    queue<int> Q;
    if (r-l == 0) return Q;
    if (r-l == 1) {
        Q.push(A[l]);
        return Q;
    }
    int h = (l+r+1)/2;
    auto L = ms(l, h), R = ms(h, r);
    for (int i = l; i < r; ++i) {
        if (R.empty() || !L.empty() && L.front() <= R.front()) {
            A[i] = L.front();
            L.pop();
        } else {
            A[i] = R.front();
            R.pop();
        }
        Q.push(A[i]);
    }
    print();
    return Q;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    ms(0, N);
}