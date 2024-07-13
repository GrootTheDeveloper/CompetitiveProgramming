#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
#define         ull         unsigned long long
#define         int         long long
#define         endl        '\n'
#define         task        "CAU1"
#define		file		ios_base::sync_with_stdio(false); cin.tie(NULL); if (fopen(task".INP", "r")) { freopen(task".INP", "r", stdin); freopen(task".OUT", "w", stdout); }
#define         Groot       signed main() 
const           int         oo = LLONG_MAX;
const           int         MAXN = 1e6 + 7;
const           int         MOD = 1e9 + 7;

using namespace std;

signed main() {
    int n, m; cin >> n >> m;
    int ans = n * (n * 2) / 2;
    cout << ans - m;
    return 0;
}