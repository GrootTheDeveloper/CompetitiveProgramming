#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

signed main() {

	int n, m; cin >> n >> m;

	vector<int>a(n);
	map<int,int> ma;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int current = m * 3 - a[i] - a[j];
			if (ma.find(current) != ma.end()) {
				ans += ma[current];
			}
		}
		ma[a[i]]++;
	}
	cout << ans;

	
}

