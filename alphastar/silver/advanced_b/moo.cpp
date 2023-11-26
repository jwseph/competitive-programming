#include <bits/stdc++.h>
using namespace std;

int N;

char sol() {
    int w = 4, o = 2;
    while (w <= N) {
        ++o;
        w = w+o+w;
    }
    while (o > 1) {
        w = (w-o)/2;
        if (N >= w+o) N -= w+o;
        if (N >= w) return 'o';
        --o;
    }
    return 'm';
}

int main() {
    cin >> N; --N;
    cout << sol() << endl;
}