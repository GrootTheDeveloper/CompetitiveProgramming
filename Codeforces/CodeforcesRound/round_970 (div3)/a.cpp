#include <bits/stdc++.h>
#include <unordered_map>
#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        bool check = false;
        if (b % 2 == 1) {
            if (a % 2 == 0 && a > 0) {
                check = true;
            }
        }
        else {
            if (a % 2 == 0) {
                check = true;
            }
        }
        if (check) cout << "yes\n";
        else cout << "no\n";
    }
}

