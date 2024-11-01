#include <bits/stdc++.h>
#include <unordered_map>
#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;
const int MOD = 1e9 + 7;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int i = 0, j = n - 1;
        bool turn = true;
        sort(a.begin(), a.end());
        while (i < j) {
            if (turn) {
                i++;
            }
            else {
                j--;
            }
            turn = !turn;

        }
        cout << a[i] << endl;
    }


    return 0;
}