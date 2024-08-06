#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

signed main() {

    int p1, q1, p2, q2;
    cin >> p1 >> q1 >> p2 >> q2;

    int left = p1 / q1 + (p1 % q1 == 0 ? 0 : 1);
    int right = p2 / q2;

    int num = right - left + 1;
    int res = num * (right + left) / 2;
    cout << res;
    return 0;
}