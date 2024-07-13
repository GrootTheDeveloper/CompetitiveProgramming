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

bool small(string & a, string & b) {
    return a + b < b + a;
}
bool large(string & a, string & b) {
    return a + b > b + a;
}
signed main() {
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string S_size = "";
    sort(a.begin(), a.end(), small);
    for (auto i : a) {
        S_size += i;
    }
    string XL_size = "";
    sort(a.begin(), a.end(), large);
    for (auto i : a) {
        XL_size += i;
    }
    cout << S_size << endl << XL_size;
    return 0;
}
