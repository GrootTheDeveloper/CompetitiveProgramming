#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;


signed main() {
    int testCase; cin >> testCase;
    while (testCase--) {
        string s, t;
        cin >> s >> t;
        int idxS = 0, idxT = 0, n = s.size(), m = t.size();

        while (idxS < n && idxT < m) {
            if (s[idxS] == t[idxT] || s[idxS] == '?') {
                s[idxS] = t[idxT];
                idxT++;
            }
            idxS++;
        }

        if (idxT == m) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                if (s[i] == '?') {
                    s[i] = 'a';
                }
            }
            cout << s << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
