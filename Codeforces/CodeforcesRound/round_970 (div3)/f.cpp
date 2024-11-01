#include <bits/stdc++.h>
#include <unordered_map>
#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;

const int MOD = 1e9 + 7;
int mod_pow(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0, sum_squares = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum = (sum + a[i]) % MOD;
            sum_squares = (sum_squares + a[i] * a[i]) % MOD;
        }

        int P = (sum * sum - sum_squares + MOD) % MOD;
        P = (P * mod_pow(2, MOD - 2, MOD)) % MOD;
        int Q = (n * (n - 1) / 2) % MOD;
        int Q_inv = mod_pow(Q, MOD - 2, MOD);

        int result = (P * Q_inv) % MOD;
        cout << result << endl;
    }

    return 0;
}