#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;


signed main() {
    int t; cin >> t;
    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;

        vector<pair<int, int>> tasks(n);
        for (int i = 0; i < n; i++) {
            cin >> tasks[i].first >> tasks[i].second;
        }

        sort(tasks.begin(), tasks.end());

        bool can_shower = false;
        if (tasks[0].first >= s) {
            can_shower = true;
        }

        for (int i = 1; i < n && !can_shower; i++) {
            if (tasks[i].first - tasks[i - 1].second >= s) {
                can_shower = true;
            }
        }

        if (!can_shower && m - tasks[n - 1].second >= s) {
            can_shower = true;
        }

        if (can_shower) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
