#include <bits/stdc++.h>
#include <unordered_map>
//#include "debug.h"

#pragma GCC optimize ("O3")

#define int long long
using namespace std;
const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6;
const int MAX = 1e6;
int n, q;
vector<int> a;
vector<vector<int>> type_arr;

vector<int>tree;

void sub1();
void sub2();
void sub3();

void build(int node, int start, int end);
void update(int node, int start, int end, int idx, int value);
int get(int node, int start, int end, int l, int r);

signed main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> n >> q;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int type1 = 0, type2 = 0, cnt = 0 ;
	int t = q;
	while (t--) {
		int type; cin >> type;
		if (type == 1) {
			int i, c; cin >> i >> c;
			type1++;
			type_arr.push_back({ 1, i,c });
		}
		else {
			type2++;
			int l, r, k; cin >> l >> r >> k;
			type_arr.push_back({ 2, l,r,k });
			if (k == 1) {
				cnt++;
			}
		}
	}

	if (n <= 200 && q <= 200)
		sub1();
	else if (type1 == 0) {
		sub2();
	}
	else if (type2 == cnt) {
		sub3();
	}
	else {
		sub1();
	}
	
}

void sub3() {
	tree.resize(4 * n + 5, 0);
	build(1, 1, n);
	int t = q;
	for (int T = 0; T < t; T++) {
		int type = type_arr[T][0];
		if (type == 1) {
			int i = type_arr[T][1], c = type_arr[T][2];
			update(1, 1, n, i, c);
		}
		else {
			int l = type_arr[T][1], r = type_arr[T][2], k = type_arr[T][3];
			int ans = get(1, 1, n, l, r);
			ans *= 2;
			cout << ans << endl;
		}
	}
}

void sub2() {
	int t = q;
	vector<vector<int>> pro(10, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		
		for (int k = 1; k <= 9; k++) {
			int temp = i;
			bool check = false;
			while (temp > 1) {
				int z = temp % 10;
				if (z == k) {
					check = true;
					break;
				}
				temp /= 10;
			}

			if (i % k == 0 || check) {
				pro[k][i] = a[i];
			}
		}
	}
	
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= n; j++) {
			pro[i][j] += pro[i][j - 1];
		}
	}
	vector<int> pre(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}

	for (int T = 0; T < t; T++) {
		int type = type_arr[T][0];

		int l = type_arr[T][1], r = type_arr[T][2], k = type_arr[T][3];
		int ans = pre[r] - pre[l - 1] + pro[k][r] - pro[k][l - 1];
		cout << ans << endl;
	}
}

void sub1() {
	int t = q;
	for(int T = 0; T < t; T++) {
		int type = type_arr[T][0];
		if (type == 1) {
			int i = type_arr[T][1], c = type_arr[T][2];
			a[i] = c;
		}
		else {
			int l = type_arr[T][1], r = type_arr[T][2], k = type_arr[T][3];
			int ans = 0;
			for (int i = l; i <= r; i++) {
				int temp = i;
				bool check = false;
				while (temp > 1) {
					int z = temp % 10;
					if (z == k) {
						check = true;
						break;
					}
					temp /= 10;
				}

				if (i % k == 0 || check) {
					ans += a[i] * 2;
				}
				else {
					ans += a[i];
				}
			}
			cout << ans << endl;
		}
	}
}

int get(int node, int start, int end, int l, int r) {
	if (r < start || end < l) {
		return 0;
	}
	if (l <= start && end <= r) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	int leftSum = get(2 * node, start, mid, l, r);
	int rightSum = get(2 * node + 1, mid + 1, end, l, r);
	return leftSum + rightSum;
}

void update(int node, int start, int end, int idx, int value) {
	if (start == end) {
		tree[node] = value;
	}
	else {
		int mid = (start + end) / 2;
		if (start <= idx && idx <= mid) {
			update(2 * node, start, mid, idx, value);
		}
		else {
			update(2 * node + 1, mid + 1, end, idx, value);
		}
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}

void build(int node, int start, int end) {
	if (start == end) {
		tree[node] = a[start];
	}
	else {
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}