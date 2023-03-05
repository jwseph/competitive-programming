#include <bits/stdc++.h>
using namespace std;

int N;

void hanoi(int n, int a, int b, int c) {
    if (n == 0) return;
    hanoi(n-1, a, c, b);
    cout << a << " --> " << c << endl;
    hanoi(n-1, b, a, c);
}

int main() {
    cin >> N;
    hanoi(N, 1, 2, 3);
}