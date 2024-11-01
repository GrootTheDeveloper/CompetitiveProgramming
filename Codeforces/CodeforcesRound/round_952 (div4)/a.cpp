#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {

    int t; cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << b[0] + a.substr(1) << " " << a[0] + b.substr(1) << endl;
    }
    return 0;
}
