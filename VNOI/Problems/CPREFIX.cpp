#include <bits/stdc++.h>

#include "debug.h"
#define int long long
#define yes cout << "yes\n"
#define no cout << "no\n"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;
const int mod = 1e9 + 7;

signed main() {
    string s;
    int n;

    cin >> s;
    n = s.size();
    s = " " + s; 
    queue<int> mq;

    vector<int> t(n + 1, 0); 
    for (int i = 2; i <= n; i++) {
        if (s[i] == s[1]) {
            mq.push(i);
        }
    }

    t[1] = 1 + mq.size();
    int idx = 2;
    while (idx <= n) {
        queue<int> cur; 
        int cnt = 1; 

        while (!mq.empty()) {
            int val = mq.front();
            mq.pop();
            if (val + 1 <= n && s[idx] == s[val + 1]) {
                cnt++;
                cur.push(val + 1); 
            }
        }

        mq = cur;
        t[idx] = cnt; 
        idx++;
    }

    for (int i = 1; i <= n; i++) {
        cout << t[i] << " ";
    }

    return 0;
}
