#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

signed main() {

	int t; cin >> t;
	while (t--) {
		int n, f, a, b;
		cin >> n >> f >> a >> b;
		vector<int> pin(n);
		for (int i = 0; i < n; i++) cin >> pin[i];

		int last = 0;
		for (int i = 0; i < n; i++) {
			int current = min((pin[i] - last) * a, b);
			last = pin[i];
			f -= current;
		}

		if (f <= 0) {
			cout << "NO";
		}
		else cout << "YES";
		cout << endl;
	}

}