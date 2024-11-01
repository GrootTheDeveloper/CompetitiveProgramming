#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {

    int t; cin >> t;
    while (t--) {

        int n; cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int dif = a[n - 1] - a[0];
        if (dif == 0) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (i == 1) {
                    cout << "B";
                }
                else cout << "R";
            }
            cout << endl;
        }
    }

    return 0;
}