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
        string s; cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') cnt++;
        }
        if (cnt > 2) cout << 'A' << endl;
        else cout << 'B' << endl;
    }
    return 0;
}

