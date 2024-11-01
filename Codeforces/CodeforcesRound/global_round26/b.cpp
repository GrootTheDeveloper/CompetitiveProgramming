#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {

    int t; cin >> t;

    while (t--) {
        vector<int> a;
        string s;
        cin >> s;
        int rem = 0;
        int se = 0;
        bool flag = false;
        for (int i = s.size() - 1; i >= 0; i--) {
            int cur = 0;
            if (i != 0) {
                cur = 10 + (s[i] - '0') - rem;
            }
            else {
                if ((s[i] - '0' - rem) == 0) {
                    flag = false;
                    break;
                }
            }


            for (int j = 5; j <= 9; j++) {
                if (cur - j >= 5 && cur - j <= 9) {
                    a.push_back(j);
                }
            }
            
            if (a.empty()) {
                flag = true;
                break;
            }
            else {
                a.clear();
                rem = 1;
            }
        }
        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}