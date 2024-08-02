#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {

    int t; cin >> t;

    vector<int>f(101, 0);

    while (t--) {
        int n; cin >> n;

        int maxValue = -1;
        int maxNum = -1;

        for (int i = 2; i <= n; i++) {
            int current = 0;
            int value = i;
            while (value <= n) {
                current += value;
                value += i;
            }
            if (current >= maxValue) {
                maxValue = current;
                maxNum = i;
            }
        }

        cout << maxNum << endl;
    }
    return 0;
}

