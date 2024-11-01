/*                  ┌───────────────────┐
					│ 0 error 0 warming │
					└───────────────────┘
	┌────────┐                              ┌────────┐
	│ Python │              ·               │ Years  │
	│        │           ·     ·            │        │
	│ Java   │         ·  Hello  ·          │ Months │
	│        │       ·             ·        │        │
	│ C++    │         ·  World! ·          │ Weeks  │
	│        │           ·     ·            │        │
	│ Line   │              ·               │  Day   │
	│        │                              │        │
	│ Line   │                              │  Day   │
	│        │                              │        │
	│  So    │                              │  No    │
	│        │                              │        │
	│ Easy   │                              │  Bug   │
	└────────┘                              └────────┘
*/

#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

signed main() {

	int t; cin >> t;
	while (t--) {
		int n, f, k;
		cin >> n >> f >> k;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];

		int numb = a[f];
		int cntF = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == numb) {
				cntF++;
			}
		}

		sort(a.begin() + 1, a.end(), greater<int>());

		int cnt = 0;
		for (int i = k + 1; i <= n; i++) {
			if (a[i] == numb) {
				cnt++;
			}
		}

		if (cntF == cnt) {
			cout << "No";
		}
		else if (cnt > 0) {
			cout << "maybe";
		}
		else cout << "yes";
		cout << endl;

	}

}

