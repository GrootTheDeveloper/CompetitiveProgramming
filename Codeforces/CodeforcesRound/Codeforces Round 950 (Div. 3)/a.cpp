#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

signed main() {

	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string s; cin >> s;
		map<char, int> ma;
		for (char i = 'A'; i <= 'G'; i++) {
			ma[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			ma[s[i]]++;
		}
		
		int answer = 0;
		for (auto it = ma.begin(); it != ma.end(); it++) {
			if (it->second < m) {
				answer += m - it->second;
			}
		}
		cout << answer << endl;
	}
	return 0;
}

