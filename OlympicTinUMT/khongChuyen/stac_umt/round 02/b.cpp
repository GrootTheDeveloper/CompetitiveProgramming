#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int reverse(int s) {
	string a = to_string(s);
	reverse(a.begin(), a.end());
	return stoll(a);
}

signed main() {
	int res = 0;
	int l, r; cin >> l >> r;
	for (int i = l; i <= r; i++) {
		if (gcd(i, reverse(i)) == 1) {
			res++;
		}
	}
	cout << res;
}

