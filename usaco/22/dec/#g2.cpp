#include <bits/stdc++.h>
using namespace std;

#define MAXN 2003
#define ll long long

struct fr {
    int n, d;
    fr() { n = d = 0; }
    fr(int n, int d) {
        if (d < 0) d = -d, n = -n;
        this->n = n, this->d = d;
    }
    fr& operator=(fr f) { swap(*this, f); return *this; }
    friend void swap(fr& a, fr& b) { swap(a.n, b.n); swap(a.d, b.d); }
    friend ostream& operator<<(ostream& out, const fr& f) { return out << f.n << '/' << f.d; }
    friend bool operator<(const fr& a, const fr& b) { return (ll)a.n*b.d < (ll)b.n*a.d; }
    friend bool operator>(const fr& a, const fr& b) { return b < a; }
    friend bool operator<=(const fr& a, const fr& b) { return !(a > b); }
    friend bool operator>=(const fr& a, const fr& b) { return !(a < b); }
    friend bool operator==(const fr& a, const fr& b) { return a <= b && a >= b; }
};

int N, Q, A[MAXN], res = 0;
map<int, fr> L[MAXN], R[MAXN];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) {
        fr r = {1, 0};
        L[i][i] = r;
        for (int j = i-1; j >= 0; --j) {
            fr c = {A[i]-A[j], i-j};
            if (c <= r) {
                r = c;
                L[i][j] = c;
                R[j][i] = c;
                ++res;
            }
        }
    }
    cin >> Q;
    while (Q--) {
        int i, dh; cin >> i >> dh; --i;
        A[i] += dh;

        fr r = {1, 0};
        for (int j = i-1; j >= 0; --j) {
            fr c = {A[i]-A[j], i-j};
            if (c <= r) {
                r = c;
                if (L[i].find(j) == L[i].end()) ++res;
                L[i][j] = c;
                R[j][i] = c;

                auto tmp = R[j].lower_bound(i);
                auto it = tmp; ++it;
                while (it != R[j].end() && it->second < c) {
                    int k = it->first;
                    R[j].erase(it);
                    L[k].erase(j);
                    --res;
                    it = tmp; ++it;
                }
            }
        }

        r = {-1, 0};
        for (int j = i+1; j < N; ++j) {
            fr c = {A[j]-A[i], j-i};
            if (c >= r) {
                r = c;
                if (R[i].find(j) == R[i].end()) ++res;
                R[i][j] = c;
                L[j][i] = c;

                auto tmp = L[j].lower_bound(i);
                auto it = tmp;
                while (it != L[j].begin() && (--it)->second > c) {
                    int k = it->first;
                    L[j].erase(it);
                    R[k].erase(j);
                    --res;
                    it = tmp;
                }
            }
        }

        cout << res << endl;
    }
}