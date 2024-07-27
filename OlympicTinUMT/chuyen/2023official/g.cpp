#include<bits/stdc++.h>
using namespace std;
int main() {

	int m, a, b;
	cin >> m >> a >> b;
	int ans1 = 0, count1 = 0;
	while (a > 0) {
		a--;
		ans1++;
		count1++;
		if (count1 >= m) {
			ans1++;
			count1 = 1;
		}
	}
	cout << ans1 << " ";
	int hour = 0, ans2 = 0, count2 = 0;
	while (hour < b) {
		ans2++;
		hour++;
		count2++;
		if (count2 == m) {
			hour++;
			count2 = 1;
		}
	}
	cout << ans2;


    return 0;
}
