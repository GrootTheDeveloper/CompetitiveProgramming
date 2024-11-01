#include <bits/stdc++.h>
#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;

bool visited[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

signed main() {

    int t; cin >> t;

    while (t--) {

        int n; cin >> n;
        vector<int>a(n);
        vector<bool> check(n + 1, false);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        check[a[0]] = true;
        bool ans = true;
        for (int i = 1; i < n; i++) {
            if (a[i] == n) {
                if (check[n - 1] == false) {
                    ans = false;
                    break;
                }
            }
            else if (a[i] == 1) {
                if (check[2] == false) {
                    ans = false;
                    break;
                }
            }
            else {
                if (check[a[i] - 1] == false && check[a[i] + 1] == false) {
                    ans = false;
                    break;
                }
            }
            check[a[i]] = true;
        }
        if (ans) yes;
        else no;
        cout << endl;
    }

    return 0;
}
