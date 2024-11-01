#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int current = -1, total = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            total += a[i];

            if (a[i] > current) {
                current = a[i];
            }

            if (current == (total - current)) {
                count++;
            }

        }
        cout << count << endl;
    }
    return 0;
}
