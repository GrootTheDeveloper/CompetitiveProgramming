#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

int quick_mod(int a, int n) {
	
	if (n == 0) return 1;

	int x = quick_mod(a, n / 2);
	x = x * x % MOD;

	if (n % 2 == 1) x = x * a % MOD;
	
	return x;
}

signed main() {
	
	vector<int> fact(1e6 + 1), inv_fact(1e6+1);
	fact[0] = 1;
	for (int i = 1; i <= 1e6; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	inv_fact[1e6] = quick_mod(fact[1e6], MOD - 2);
	for (int i = 1e6 - 1; i >= 0; i--) {
		inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
	}

	int n; cin >> n;
	while (n--) {
		int n, k; cin >> n >> k;
		cout << (fact[n] % MOD * inv_fact[k] % MOD * inv_fact[n - k] % MOD) % MOD << endl;
	}
}