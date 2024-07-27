#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int MOD1 = 998244353;
const int MOD2 = 1e9 + 2207;
const int MX = 200005;
const int base = 1LL << 6;

int h1[MX];
int h2[MX];
int bp1[MX];
int bp2[MX];

int pf[MX];
bool chk[MX];

void solve() {
    string s; cin >> s;
    int k; cin >> k;
    int n = s.length();
    if (k >= n) cout << ((n + k) >> 1 << 1), exit(0);
    s = ' ' + s + ' ';
    int ans = k * 2;

    bp1[0] = 1;
    bp2[0] = 1;
    for (int i = 1; i <= n; i++) bp1[i] = bp1[i - 1] * base % MOD1;
    for (int i = 1; i <= n; i++) bp2[i] = bp2[i - 1] * base % MOD2;
    for (int i = 1; i <= n; i++) h1[i] = (h1[i - 1] * base + s[i]) % MOD1;
    for (int i = 1; i <= n; i++) h2[i] = (h2[i - 1] * base + s[i]) % MOD2;
    int L1 = 0, R1 = 0;
    int L2 = 0, R2 = 0;
    for (int l = n / 2; l > k; l--) {
        for (int i = 1; i + l + l - 1 <= n; i++) {
            L1 = (h1[i + l - 1] - h1[i - 1] * bp1[l] + MOD1 * MOD1) % MOD1;
            L2 = (h2[i + l - 1] - h2[i - 1] * bp2[l] + MOD2 * MOD2) % MOD2;
            R1 = (h1[i + l + l - 1] - h1[i + l - 1] * bp1[l] + MOD1 * MOD1) % MOD1;
            R2 = (h2[i + l + l - 1] - h2[i + l - 1] * bp2[l] + MOD2 * MOD2) % MOD2;
            if (L1 == R1 && L2 == R2) {
                ans = max(ans, l * 2);
                break;
            }
        }
        if (L1 == R1 && L2 == R2) break;
    }

    reverse(s.begin(), s.end());
    for (int i = 1; i <= n; i++) pf[i] = 1;
    for (int i = 1, j = 2; j <= n;) {
        if (s[i] == s[j]) {
            pf[j] = ++i;
            j++;
        }
        else if (pf[i - 1]) i = pf[i - 1];
        else j++;
    }
    for (int i = 1; i <= n; i++) if (i - (pf[i] - 1) * 2 <= k) ans = max(ans, (i - pf[i] + 1) * 2);
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}


