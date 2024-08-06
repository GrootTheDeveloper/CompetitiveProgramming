#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

vector<int> f(2 * 1e5 + 5, 0);

signed main() {

    f[0] = 0;
    for (int i = 1; i <= 2 * 1e5; i++) {
        f[i] = f[i / 3] + 1;
    }

    int testCase; cin >> testCase;
    while (testCase--) {
        int l, r;
        cin >> l >> r;
        int operations = 0;

        operations += f[l];

        for (int i = l + 1; i <= r; i++) {
            operations += f[i];
        }
        operations += f[l];
        cout << operations << endl;
    }
}