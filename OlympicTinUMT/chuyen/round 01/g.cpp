const int MOD = 1e9 + 7;
long long dp[2025][2025];
long long expo(long long base, long long exponent, long long mod) {
	long long ans = 1;
	while (exponent != 0) {
		if ((exponent & 1) == 1) ans = (ans * base) % mod;
		base = (base * base) % mod;
		exponent >>= 1;
	}
	return ans % mod;
}
///// Subtask 1, 2, 3

long long solve(long long n, long long pow) {
	long long res = 0;
	long long c_n_i = 1;
	for (long long i = 1; i <= n; ++i) {
		c_n_i = (((c_n_i * (n - i + 1)) % MOD) * expo(i, MOD - 2, MOD))
			% MOD;
		long long temp = (c_n_i * expo(i, pow, MOD)) % MOD;
		res = (res + temp) % MOD;
	}
	return res;
}
/////
///// Subtask 4
void solve() {
	int n; cin >> n;
	int pow = 2024;
	if (n >= pow) {
		for (int j = 0; j <= min(pow, n); ++j) dp[0][j] = expo(2, n - j,
			MOD) - 1;
		for (int i = 1; i <= min(pow, n); ++i) {
			for (int j = 0; j <= min(pow, n) - i; ++j) {
				dp[i][j] = (((n - j) * dp[i - 1][j + 1]) % MOD + (j *
					dp[i - 1][j]) % MOD + ((n - j) * expo(j + 1, i - 1, MOD)) % MOD) %
					MOD;
			}
		}
		cout << dp[pow][0];
	}
	else {
		cout << solve(n, pow);
	}
}
/////