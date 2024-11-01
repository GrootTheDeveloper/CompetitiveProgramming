#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;


signed main() {

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<string>grid(n);
		for (int i = 0; i < n; i++) {
			cin >> grid[i];
		}

		for (int i = 0; i < n; i += m) {
			for (int j = 0; j < n; j += m) {
				cout << grid[i][j];
			}
			cout << endl;
		}

	}

}
