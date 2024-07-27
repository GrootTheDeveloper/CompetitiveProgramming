#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
using namespace std;



int main()
{
	long long n;
	vector <long long> a;
	long long x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x > n) x = n;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	long long kq = 1;
	for (int i = 0; i < n; i++)
	{
		kq = ((kq % MOD) * ((a[i] - i) % MOD)) % MOD;
	}
	cout << kq;
}
