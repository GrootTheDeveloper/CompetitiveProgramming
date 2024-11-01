#include <bits/stdc++.h>
#include <unordered_map>
#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>p(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        string s; cin >> s;
        s = " " + s;
        vector<int> result(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (result[i] != 0) continue;
            int value = i;
            vector<int> cycle;
            while (true) {
                cycle.push_back(value);
                value = p[value];
                if (value == i) break;
            }
            int black = 0;
            for (int v : cycle) {
                if (s[v] == '0') black++;
            }
            for (int v : cycle) {
                result[v] = black;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}