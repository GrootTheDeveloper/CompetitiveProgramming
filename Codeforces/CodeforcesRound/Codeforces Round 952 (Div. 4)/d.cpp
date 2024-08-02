#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {

    int t; cin >> t;

    vector<int>f(101, 0);

    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        bool firstCheck = false;
        pair<int, int> firstE, secondE;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == '#') {
                    if (firstCheck == false) {
                        firstCheck = true;
                        firstE = { i + 1, j + 1 };
                    }
                    secondE = { i + 1, j + 1 };
                }
            }
        }
        cout << (firstE.first + secondE.first) / 2 << " " << firstE.second << endl;

    }
    return 0;
}
