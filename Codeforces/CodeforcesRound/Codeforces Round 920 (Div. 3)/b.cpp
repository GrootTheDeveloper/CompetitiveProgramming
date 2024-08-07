#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

signed main() {

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string ss, ts;
		cin >> ss >> ts;

		int count_first = 0, count_second = 0;

		for (int i = 0; i < n; i++) {
			if (ss[i] == ts[i]) continue;

			if (ss[i] == '1') {
				count_first++;
			}
			if (ts[i] == '1') {
				count_second++;
			}
		}
		int ans;
		if (count_first == count_second) {
			ans = count_first;
		}
		else if (count_second > count_first) {
			ans = count_second;
		}
		else {
			ans = count_first;
		}
		cout << ans << endl;
	}

}