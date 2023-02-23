#include <bits/stdc++.h>
using namespace std;

#define N_MAX 01'0000'0000

int T;
queue<int> Q;
unordered_map<int, pair<int, char>> V;

int tf(int i, char C) {
    int r = 0;
    switch (C) {
        case 'A': {  // swap top and bottom row
            for (int j = 0; j < 8; ++j) {
                r <<= 3;
                r |= i&7;
                i >>= 3;
            }
            break;
        }
        case 'B': {  // shift right
            r |= i<<3 & 00000'7770;
            r |= i>>9 & 00000'0007;
            r |= i>>3 & 00777'0000;
            r |= i<<9 & 07000'0000;
            break;
        }
        case 'C': {  // rotate middle four squares clockwise
            r |= i     & 07007'7007;
            r |= i>>3  & 00070'0070;
            r |= i>>9  & 00000'0700;
            r |= i<<15 & 00700'0000;
            break;
        }
    }
    return r;
}

string gen(int i) {
    string r;
    while (V[i].first > 0) {
        auto &p = V[i];
        r.push_back(p.second);
        i = p.first;
    }
    reverse(r.begin(), r.end());
    return r;
}

int main() {
    T = 0;
    for (int i = 0; i < 8; ++i) {
        int x; cin >> x;
        T <<= 3;
        T |= x-1;
    }
    Q.push(00123'4567);
    V[Q.front()] = {-1, 'Z'};
    while (!Q.empty() && Q.front() != T) {
        int i = Q.front();
        Q.pop();
        for (char C = 'A'; C <= 'C'; ++C) {
            int j = tf(i, C);
            if (V.find(j) != V.end()) continue;
            V[j] = {i, C};
            Q.push(j);
        }
    }
    string S = gen(Q.front());
    cout << S.size() << endl;
    cout << S << endl;
}