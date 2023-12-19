#include <bits/stdc++.h>
using namespace std;

int T, N;
string S;
unordered_set<int> targets;
unordered_map<int, int> hit, hitrr, hitr, hitl, hitll;
int res = 0;

bool has_target(int x) {
    return targets.find(x) != targets.end();
}

int main() {
    cin >> T >> N;
    while (T--) {
        int t; cin >> t;
        targets.insert(t);
    }
    cin >> S;
    int x = 0, shot = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'L') --x;
        if (S[i] == 'R') ++x;
        if (S[i] == 'F') {
            shot += !hit[x] && has_target(x);
            ++hit[x];
        }
    }
    res = max(res, shot);
    int shotrr = 0, shotr = 0, shotl = 0, shotll = 0;
    for (int i = N-1; i >= 0; --i) {
        if (S[i] == 'L') {
            ++x;
            res = max(res, shot+shotrr);
            res = max(res, shot+shotr+(!hit[x] && !hitr[x] && has_target(x)) );
        }
        if (S[i] == 'R') {
            --x;
            res = max(res, shot+shotll);
            res = max(res, shot+shotl+(!hit[x] && !hitl[x] && has_target(x)) );
        }
        if (S[i] == 'F') {
            --hit[x];
            if (has_target(x)) {
                if (!hit[x]) {
                    --shot;
                    if (hitrr[x]) ++shotrr;
                    if (hitr[x]) ++shotr;
                    if (hitl[x]) ++shotl;
                    if (hitll[x]) ++shotll;
                }
            }
            res = max({res, shot+shotl, shot+shotr});
            if (hitrr[x+2] == 0 && hit[x+2] == 0) shotrr += has_target(x+2);
            if (hitr[x+1] == 0 && hit[x+1] == 0) shotr += has_target(x+1);
            if (hitl[x-1] == 0 && hit[x-1] == 0) shotl += has_target(x-1);
            if (hitll[x-2] == 0 && hit[x-2] == 0) shotll += has_target(x-2);
            ++hitrr[x+2];
            ++hitr[x+1];
            ++hitl[x-1];
            ++hitll[x-2];
        }

    }
    cout << res << endl;
}