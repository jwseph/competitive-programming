#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    cin >> s; n = s.size();
    sort(s.begin(), s.end());
    for (int i = n-1; i >= 0; --i) {
        if (i == n-1 )
    }

    while (pq.size() > 1) {
        auto [c1, f1] = pq.top(); pq.pop();
        while (f1 > 0) {

        }
        s.push_back(c1);
        // AAHIITTTTV |     safe=V
        // AAHIITTT | VT
        // AAHITT | ITVT
        // AAHT | ITITVT
        // AHATITITVT
        // AAHIITTTTV |     safe=V
        // AAHIITTTT | .V
        // AAHIITTT | .TV
        // AAHIITT | T.TV
        // AAHIITT | .TVT
        // AAHIIT | T.TVT
        // AAHIT | .TITVT
        // AAHI | T.TITVT
        // AAH | TITITVT
        //   ^
    }
}