#include <bits/stdc++.h>
#include <unordered_map>
#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;


signed main() {

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> a(n), f(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        f[0] = a[0];
        for (int i = 1; i < n; i++) {
            f[i] = f[i - 1] + a[i];
        }
        string s; cin >> s;

        queue<int> l, r;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') l.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'R') r.push(i);
        }
        int point = 0;
        while (!l.empty() && !r.empty()) {
            int left = l.front();
            int right = r.front();
            l.pop(); r.pop();
            if (left > right) {
                break;
            }
            point += f[right] - (left == 0 ? 0 : f[left - 1]);
        }
        cout << point << endl;
    }

    return 0;
}