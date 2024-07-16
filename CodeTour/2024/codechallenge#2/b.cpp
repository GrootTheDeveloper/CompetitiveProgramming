#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
#define         ull         unsigned long long
#define         int         long long
#define         endl        '\n'
#define         task        "CAU1"
#define			file		if (fopen(task".INP", "r")) { freopen(task".INP", "r", stdin); freopen(task".OUT", "w", stdout); }
#define         I           ios_base::sync_with_stdio(false);
#define         am          cout.tie(NULL);
#define         Groot       cin.tie(NULL);
const           int         oo = LLONG_MAX;
const           int         MAXN = 1e6 + 7;
const           int         MOD = 1e9 + 7;

using           namespace   std;
vector<int> fact, inv_fact;
inline          void        add(int& x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod; }
inline          void        mul(int& x, int y, int mod = MOD) { x = (x * 1LL * y) % mod; }

inline          int         prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x; }
inline          int         sum(int x, int y, int mod = MOD) { return add(x, y, mod), x; }
inline          int         bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1; } return ans; }
inline          int         Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod); }
inline			int			eulerPhi(int N) { int result = N; for (int p = 2; p * p <= N; ++p) while (N % p == 0) { result -= result / p; while (N % p == 0) N /= p; } if (N > 1) result -= result / N; return result; }

inline          int         gcd(int a, int b) { while (b != 0) { int temp = b; b = a % b; a = temp; } return a; }
inline          int         lcm(int a, int b) { return a / gcd(a, b) * b; }

inline			void		tienXuLy_GiaiThua(int max_n, int mod = MOD) { fact.resize(MAXN); inv_fact.resize(MAXN); fact[0] = 1; for (int i = 1; i <= max_n; ++i) fact[i] = fact[i - 1] * 1LL * i % mod; inv_fact[max_n] = bpow(fact[max_n], mod - 2, mod); for (int i = max_n - 1; i >= 0; --i) inv_fact[i] = inv_fact[i + 1] * 1LL * (i + 1) % mod; }
inline          int         toHop(int n, int k, int mod = MOD) { if (k > n) return 0; vector<int> fact(n + 1, 1); for (int i = 2; i <= n; i++) { fact[i] = fact[i - 1] * 1LL * i % mod; } return fact[n] * 1LL * Inv(fact[k], mod) % mod * Inv(fact[n - k], mod) % mod; }
inline			int			chinhHop(int n, int k, int mod = MOD) { if (k > n) return 0; vector<int> fact(n + 1, 1); for (int i = 2; i <= n; i++) fact[i] = fact[i - 1] * 1LL * i % mod; return fact[n] * 1LL * Inv(fact[n - k], mod) % mod; }

inline          int         maxSubArray(const vector<int>& arr) { int max_so_far = arr[0], max_ending_here = arr[0]; for (size_t i = 1; i < arr.size(); i++) { max_ending_here = max(arr[i], max_ending_here + arr[i]); max_so_far = max(max_so_far, max_ending_here); } return max_so_far; }
inline          int         compute_sum(int n) { int res = 0; int combination = 1; for (int i = 1; i <= n; ++i) { combination = combination * (n - i + 1) % MOD * bpow(i, MOD - 2, MOD) % MOD; int term = combination * bpow(i, 2024, MOD) % MOD; res = (res + term) % MOD;
    }
    return res;
}

inline          bool        isPrime(int n) { if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (int i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true; }

inline          string      longestDoiXung(const string& s) { if (s.empty()) return ""; int n = s.size(), start = 0, maxLen = 1; vector<vector<bool>> dp(n, vector<bool>(n, false)); for (int i = 0; i < n; ++i) dp[i][i] = true; for (int len = 2; len <= n; ++len) for (int i = 0; i <= n - len; ++i) { int j = i + len - 1; if (s[i] == s[j] && (len == 2 || dp[i + 1][j - 1])) { dp[i][j] = true; if (len > maxLen) { maxLen = len; start = i; } } } return s.substr(start, maxLen); }
inline          string      addBigNum(string num1, string num2) { if (num1.length() > num2.length()) swap(num1, num2); string str = ""; int n1 = num1.length(), n2 = num2.length(), diff = n2 - n1, carry = 0; for (int i = n1 - 1; i >= 0; i--) { int sum = ((num1[i] - '0') + (num2[i + diff] - '0') + carry); str.push_back(sum % 10 + '0'); carry = sum / 10; } for (int i = n2 - n1 - 1; i >= 0; i--) { int sum = ((num2[i] - '0') + carry); str.push_back(sum % 10 + '0'); carry = sum / 10; } if (carry) str.push_back(carry + '0'); reverse(str.begin(), str.end()); return str; }
inline          string      minusBigNum(string num1, string num2) { if (num1 == num2) return "0"; bool neg = false; if (num1 < num2) { swap(num1, num2); neg = true; } string str = ""; int n1 = num1.length(), n2 = num2.length(), diff = n1 - n2, carry = 0; for (int i = n2 - 1; i >= 0; i--) { int sub = ((num1[i + diff] - '0') - (num2[i] - '0') - carry); if (sub < 0) { sub = sub + 10; carry = 1; } else carry = 0; str.push_back(sub + '0'); } for (int i = n1 - n2 - 1; i >= 0; i--) { if (num1[i] == '0' && carry) { str.push_back('9'); continue; } int sub = ((num1[i] - '0') - carry); if (i > 0 || sub > 0) str.push_back(sub + '0'); carry = 0; } if (neg) str.push_back('-'); reverse(str.begin(), str.end()); return str; }



signed main() {

    I am Groot;
    
    int m; cin >> m;
    int tmp = m;
    vector<int> a;
    for (int i = 2; i * i <= m; i++) {
        if (tmp % i == 0) {
            while (tmp % i == 0) {
                tmp /= i;
            }
            a.push_back(i % 26);
        }
    }
    if (tmp > 1) a.push_back(tmp % 26);
    sort(a.begin(), a.end());
    string s;
    for (int i = 0; i < a.size(); i++) {
        s += a[i] + 'A';
    }
    cout << s;

    return 0;
}