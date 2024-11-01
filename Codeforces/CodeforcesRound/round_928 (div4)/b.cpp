#include <bits/stdc++.h>
#include <unordered_map>
#include "debug.h"
#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;
const int MOD = 1e9 + 7;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string>s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        bool flag = false;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (s[i][j] == '1') {
                    cnt++;
                }
            }
            if (cnt == 1) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "TRIANGLE\n";
        else cout << "SQUARE\n";
    }

    return 0;
}

