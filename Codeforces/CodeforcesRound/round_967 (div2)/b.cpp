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
        int n;
        cin >> n;
        vector<int> a(n, -1);
        int num = 1;
        int i = 0, j = n - 1;

        if (n % 2 == 0) {
            cout << -1 << endl;
        }
        else {
            while (num <= n) {
                if (i <= j && a[i] == -1) {
                    a[i] = num;
                    num++;
                    i++;
                }

                if (j >= i && a[j] == -1) {
                    a[j] = num;
                    num++;
                    j--;
                }
            }

            for (int k = 0; k < n; k++) {
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}