#include <bits/stdc++.h>
#include <unordered_map>

#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;
const int MOD = 1e9 + 7;

int digit_sum(int u) {
    int result = 0;
    while (u > 0) {
        result += u % 10;
        u /= 10;
    }
    return result;
}
signed main() {
    int t;
    cin >> t;

    vector<int>dp(2e5 + 5, 0);
    dp[0] = 0;
    for (int i = 1; i <= 2e5; i++) {
        dp[i] = digit_sum(i) + dp[i - 1];
    }
    while (t--) {
        int n; cin >> n;
        cout << dp[n] << endl;
    }
}