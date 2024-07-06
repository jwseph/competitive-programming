#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

using H = array<int, 2>;
H operator+(H l, H r) {
	for (int i = 0; i < 2; ++i) if ((l[i] += r[i]) >= mod) l[i] -= mod;
	return l; }
H operator-(H l, H r) {
	for (int i = 0; i < 2; ++i) if ((l[i] -= r[i]) < 0) l[i] += mod;
	return l; }
H operator*(H l, H r) {
	for (int i = 0; i < 2; ++i) l[i] = (ll)l[i]*r[i]%mod;
	return l; }

mt19937 rng((random_device())());
uniform_int_distribution<int> bdist(.1*mod, .9*mod);  // not too close to ends
const H base{bdist(rng), bdist(rng)};
vector<H> pows{{1, 1}};
struct HashRange {
	string s; vector<H> pre{{}};
	void add(char c) { s += c, pre.push_back(base*pre.back() + H{c, c}); }
	void add(string t) { for (char c: t) add(c); }
	void extend(int len) {
        while (pows.size() <= len) pows.push_back(base*pows.back());
    }
	H hash(int l, int r) {
        int len = r-l; extend(len);
		return pre[r]-pre[l]*pows[len];
    }
    int lcp(HashRange& rk, int i, int j) {
        int l = 0, r = min(s.size()-i, rk.s.size()-j);
        while (l < r) {
            int h = (l+r+1)/2;
            if (hash(i, i+h) == rk.hash(j, j+h)) l = h;
            else r = h-1;
        }
        return l;
    }
};
/// HashRange HR; HR.add("ababab"); F0R(i,6) FOR(j,i,6) ps(i,j,HR.hash(i,j));

int main() {
    HashRange a, b;
    a.add("abcd");
    b.add("abc");
    cout << HashRange(a).hash(0, 3)[0] << endl;
    cout << HashRange(b).hash(0, 3)[0] << endl;
}