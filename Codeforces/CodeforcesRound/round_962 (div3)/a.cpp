#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;


signed main() {

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int cow = n / 4;
		int chicken = (n % 4 != 0 ? 1 : 0);
		cout << cow + chicken << endl;
	}

}
