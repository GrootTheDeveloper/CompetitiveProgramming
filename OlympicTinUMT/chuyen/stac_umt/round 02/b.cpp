#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x == y) {
			cout << a << endl;
			continue;
		}

		int res = 0;
		int dif = abs(x - y);
		if (x < y) {
			res = min(b * dif + a, a + a * 2 * dif);
		}
		else {
			res = min(a + b * (dif - 1), a + a * 2 * (dif - 1));
		}
		cout << res << endl;
	}
}
