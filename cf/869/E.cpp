#include <bits/stdc++.h>
using namespace std;

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define MN 2503
#define ll long long

int R, C, NQ;

ll T[MN][MN]{};
void update(int r, int c, ll v) {
    for (int i = r; i; i &= i-1) {
        for (int j = c; j; j &= j-1) {
            T[i-1][j-1] ^= v;
        }
    }
}
int query(int r, int c) {
    ll res = 0;
    for (int i = r; i < R; i |= i+1) {
        for (int j = c; j < C; j |= j+1) {
            res ^= T[i][j];
        }
    }
    return res;
}

int main() {
    // 2D fenwick with rectangle hash
    // Two points can meet each other if they are in exactly the same rectangles
    cin >> R >> C >> NQ;
    chash ch{};
    while (NQ--) {
        int t, r1, c1, r2, c2; cin >> t >> r1 >> c1 >> r2 >> c2;
        --r1; --c1;
        if (t < 3) {
            ll h = ch(ch(ch(ch(r1)^ch(c1))^ch(r2))^ch(c2));
            update(r2, c2, h);
            update(r2, c1, h);
            update(r1, c2, h);
            update(r1, c1, h);
            continue;
        }
        --r2; --c2;
        cout << (query(r1, c1) == query(r2, c2) ? "Yes" : "No") << endl;
    }
}