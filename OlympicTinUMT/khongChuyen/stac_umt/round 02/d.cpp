#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

int quick(int a, int p) {

	if (p == 0) return 1;

	int x = quick(a, p / 2);

	if (p % 2 == 1) return x * x * a;
	return x * x;
}

int convert(string s) {
	int res = 0, j = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		res += (s[i] - '0') * quick(2, j);
		j++;
	}
	return res;
}

signed main() {

	string a, b;
	cin >> a >> b;

	int l = convert(a), r = convert(b);
	int res = floor(sqrt(r)) - ceil(sqrt(l)) + 1;
	cout << res;
}
