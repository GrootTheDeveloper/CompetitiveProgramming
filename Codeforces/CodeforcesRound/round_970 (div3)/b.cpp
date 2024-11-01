#include <bits/stdc++.h>
#include <unordered_map>
#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;

bool isSquare(int n) {
    int root = sqrt(n);
    return root * root == n;
}

bool check(string s, int n) {
    int side = sqrt(n);

    for (int i = 0; i < side; ++i) {
        if (s[i] != '1' || s[n - 1 - i] != '1') {
            return false;
        }
    }

    for (int i = 0; i < side; ++i) {
        if (s[i * side] != '1' || s[(i + 1) * side - 1] != '1') {
            return false;
        }
    }

    for (int i = 1; i < side - 1; ++i) {
        for (int j = 1; j < side - 1; ++j) {
            if (s[i * side + j] != '0') {
                return false;
            }
        }
    }

    return true;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        if (isSquare(n) && check(s, n)) {
            yes;
        }
        else {
            no;
        }
    }
}