#include <bits/stdc++.h>
using namespace std;
#define int long long
#define m 1000000007

void multiply(int a[2][2], int b[2][2]) {
	int mul[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			mul[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				int tmp = (a[i][k] * b[k][j]) % m;
				if (tmp < 0) tmp += m;
				mul[i][j] = (mul[i][j] + tmp) % m;
			}
		}
	}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			b[i][j] = mul[i][j];
}

int power(int F[2][2], int n) {
	int M[2][2] = { {6, -7}, {1, 0} };
	while (n) {
		if (n & 1) {
			multiply(M, F);
		}
		multiply(M, M);
		n >>= 1;
	}
	return F[0][0];
}
int findNthTerm(int n) {
	int F[2][2] = { {8, 0}, { 2, 0} };
	if (n == 0) return 1;
	if (n == 1) return 2;
	if (n == 2) return 8;
	return power(F, n - 2);
}

signed main() {
	int n;
	cin >> n;
	cout << findNthTerm(n);
	return 0;
}