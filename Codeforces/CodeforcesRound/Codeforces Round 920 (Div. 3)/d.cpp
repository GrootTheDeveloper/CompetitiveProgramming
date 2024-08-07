#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

signed main() {

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;

		vector<int>a(n), b(m);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int result = 0;
		int i = 0, j = m - 1;
		int x = 0, y = n - 1;
		while (x < y) {
			int dif1 = abs(a[x] - b[j]), dif2 = abs(a[y] - b[i]);
			if (dif1 <= dif2) {
				result += dif2;
				y--, i++;
			}
			else {
				result += dif1;
				x++, j--;
			}
		}

		if (x == y) {
			result += max(abs(a[y] - b[i]), abs(a[x] - b[j]));
		}

		cout << result << endl;
	}

}