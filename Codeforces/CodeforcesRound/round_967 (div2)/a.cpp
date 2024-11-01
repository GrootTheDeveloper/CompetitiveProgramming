#include <bits/stdc++.h>
#include <unordered_map>
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
        map<int, int> ma;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            ma[x]++;
        }
        int ans = 0;
        for (auto it : ma) {
            ans = max(ans, it.second);
        }
        cout << n - ans << endl;
    }
    return 0;
}