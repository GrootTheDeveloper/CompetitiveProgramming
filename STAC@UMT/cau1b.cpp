#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e7;
const int MAX = 2e5;

string s = "STAC_CNTT";
int n;
int ans = 0;

set<string> ms;
vector<bool> used(10, false);
void cnt(int idx, int len, string &t){
    if (t.size() == len) {
        ms.insert(t);
        return;
    }
    if (idx == n) return;

    for (int i = 0; i < n; i++) {
        if (used[i] == false) {
            used[i] = true;
            t += s[i];
            cnt(0, len, t);
            t.pop_back();
            used[i] = false;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    n = s.size();
    int dif = 0;
    vector<int> ans(10, 0);
    for (int len = 1; len <= n; len++) {
        string temp;
        cnt(0, len, temp);
        ans[len] = ms.size() - dif;
        dif += ans[len];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cout << "chuoi co " << i << " ki tu: " << ans[i] << endl;
        sum += ans[i];
    }
    cout << "Tong la: " << sum;

    return 0;
}


