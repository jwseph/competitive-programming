#include <bits/stdc++.h>
using namespace std;

ifstream fin("race.in");
ofstream fout("race.out");

int K, N;

int sol(int X) {
    int A = 0, B = 0, T = 0;
    for (int S = 1;; ++S) {
        A += S;
        ++T;
        if (A+B >= K) return T;
        if (S >= X) {
            B += S;
            ++T;
            if (A+B >= K) return T;
        }
    }
    return INT_MAX;
}

int main() {
    fin >> K >> N;
    while (N--) {
        int X; fin >> X;
        fout << sol(X) << endl;
    }
}