#include <bits/stdc++.h>

//#include "debug.h"
#define int long long
#define yes cout << "yes\n"
#define no cout << "no\n"
#define endl '\n';

using namespace std;
const int oo =  LLONG_MAX;
const int mod = 1e9 + 7;

int n, hashValue[100005], power27[100005];
string s;
vector<int> t(100005, 0), a(100005, 0);

int get_hash(int i, int j) {
    return (hashValue[j] - hashValue[i - 1] * power27[j - i + 1]);
}

signed main() {
    
    cin >> s;
    n = s.size();
    s = " " + s; 

    power27[0] = 1;
    for (int i = 1; i <= n; i++) {
        power27[i] = power27[i - 1] * 27;
    }

    for (int i = 1; i <= n; i++) {
        hashValue[i] = hashValue[i - 1] * 27 + s[i] - 'a' + 1;
    }

    for (int i = 1; i <= n; i++) {
        int l = 1, r = n - i + 1;
        int k = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (get_hash(1, mid) == get_hash(i, i + mid - 1)) {
                k = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        a[1]++;
        if (k + 1 <= n) a[k + 1]--;
    }

    for (int i = 1; i <= n; i++) {
        t[i] = t[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << t[i] << " ";
    }


    return 0;
}