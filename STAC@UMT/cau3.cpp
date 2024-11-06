#include <bits/stdc++.h>
#include <unordered_map>

#pragma GCC optimize ("O3")
#define int long long
using namespace std;

const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e7;
const int MAX = 2e5;

void a() {
    int n; cin >> n;
    vector<int>digit;
    while (n > 0) {
        digit.push_back(n % 10), n /= 10;
    }
    bool check = true;
    for (int i = 0; i < digit.size() / 2; i++) {
        if (digit[i] != digit[digit.size() - i - 1]) {
            check = false;
            break;
        }
    }
    if (check)cout << "Yes";
    else cout << "No";
}

void b() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int cur = a[i] + a[j];
            int temp = cur;
            bool check = true;
            for (int k = 2; k * k <= cur; k++) {
                if (cur % k == 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                cout << a[i] << " + " << a[j] << " = " << cur << " phan tich : ";
                map<int, int> ma;
                for (int k = 2; k * k <= cur; k++) {
                    while (temp % k == 0) {
                        temp /= k;
                        ma[k]++;
                    }
                }
                if (temp > 1) ma[temp]++;
                for (auto it = ma.begin(); it != ma.end(); it++) {
                    if (it != prev(ma.end())) {
                        cout << it->first << "^" << it->second << " x ";
                    }
                }
                cout << prev(ma.end())->first << "^" << prev(ma.end())->second << endl;
            }
        }
    }

}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    a();
    b();
    return 0;
}
