#include <bits/stdc++.h>
#include <unordered_map>
#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;
const int MOD = 1e9 + 7;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
signed main() {


    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        vector<int> q(n);
        q[0] = p[n - 1];
        for (int i = 1; i < n; ++i) {
            q[i] = p[i - 1];
        }

        for (int i = 0; i < n; ++i) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
    return 0;
}