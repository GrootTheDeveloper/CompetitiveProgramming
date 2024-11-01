#include <bits/stdc++.h>
#include <unordered_map>
#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        int length = 0;
        int current = l;

        while (current <= r) {
            length++;
            current += length;
        }

        cout << length << endl;
    }
}