#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;



signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;

        a = " " + a;
        b = " " + b;

        vector<vector<int>> freqA(n + 1, vector<int>(26, 0));
        vector<vector<int>> freqB(n + 1, vector<int>(26, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                freqA[i][j] = freqA[i - 1][j];
                freqB[i][j] = freqB[i - 1][j];
            }
            freqA[i][a[i] - 'a']++;
            freqB[i][b[i] - 'a']++;
        }

        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            int changesNeeded = 0;

            for (int c = 0; c < 26; ++c) {
                int countA = freqA[r][c] - freqA[l - 1][c];
                int countB = freqB[r][c] - freqB[l - 1][c];
                if (countA != countB) {
                    changesNeeded += abs(countA - countB);
                }
            }

            cout << changesNeeded / 2 << endl;
        }
    }
    return 0;
}
