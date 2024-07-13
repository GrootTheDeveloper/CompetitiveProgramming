#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
#define         ull         unsigned long long
#define         int         long long
#define         ldb         long double
#define         endl        '\n'
#define         task        "CAU1"
#define		file		ios_base::sync_with_stdio(false); cin.tie(NULL); if (fopen(task".INP", "r")) { freopen(task".INP", "r", stdin); freopen(task".OUT", "w", stdout); }
#define         Groot       signed main() 
const           int         oo = LLONG_MAX;
const           int         MAXN = 1e6 + 7;
const           int         MOD = 1e9 + 7;

using namespace std;

bool cmp(pair<ldb, ldb> a, pair<ldb, ldb> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;

}

signed main() {

    ldb m, n, a, b, c;
    cin >> m >> n >> a >> b >> c;

    ldb A = a, B = b - m, C = c - n;
    ldb denta = pow(B, 2) - 4.0 * A * C;

    // x = - B +- sqrt(denta) / (2*a)

    vector<pair<ldb, ldb>> ans;

    if (denta == 0.000) {
        ldb x = (-B) / (2 * A);
        ldb y = (x * m + n);
        ans.push_back({ x,y });
    }
    else if (denta > 0.000) {
        ldb x1 = (-B + sqrt(denta)) / (2 * A);
        ldb y1 = x1 * m + n;
        ldb x2 = (-B - sqrt(denta)) / (2 * A);
        ldb y2 = x2 * m + n;

        ans.push_back({ x1,y1 });
        ans.push_back({ x2,y2 });
    }
    if (ans.empty()) {
        cout << "KHONG TON TAI";
    }
    else {
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end(), cmp);
        for (auto i : ans) {
            cout << fixed << setprecision(3) << i.first << " " << i.second << endl;
        }
    }
    return 0;
}