#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

signed main() {

	int p, q; cin >> p >> q;

	if (q % p != 0) {
		cout << -1;
		return 0;
	}

	int res = LLONG_MAX;
	int k = q / p;
	for (int i = 1; i * i <= k; i++) {
		if (k % i == 0) {

			int m = i, n = k / i;

			if (gcd(m, n) == 1) {
				res = min(res, min(p * m + p * n, q * n + q * m));
			}
		}
	}
	cout << res << endl;
}
