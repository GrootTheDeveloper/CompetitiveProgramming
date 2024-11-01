#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    
    int t; cin >> t;

    vector<int>f(101, 0);

    while (t--) {
        int x, y, z, k;
        cin >> x >> y >> z >> k;
        int total = x * y * z;
        if (k > total) {
            cout << 0 << endl;
            continue;
        }
        else if (k == total) {
            cout << 1 << endl;
            continue;
        }
        int maxDT = 0;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (i * j > k) break;
                int l = 1, r = z;
                while(l <= r) {
                    int q = (l + r) / 2;
                    if (i * j * q == k) {
                        int miss = (x - i + 1) * (y - j + 1) * (z - q + 1);
                        maxDT = max(maxDT, miss);
                        break;
                    }

                    else if (i * j * q > k) {
                        r = q - 1;
                    }
                    else {
                        l = q + 1;
                    }
                }
            }
        }
        cout << maxDT << endl;
    }
    return 0;
}
    