#include<bits/stdc++.h>
using namespace std;
int main() {

    long long n;
    cin >> n;
    long long quadrant1 = 0, quadrant2 = 0, quadrant3 = 0, quadrant4 = 0;
    vector <pair<long long, long long>> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (long long i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    for (long long i = 0; i < n; i++) {
        long long x = a[i].first, y = a[i].second;
        if (x == 0 || y == 0) {
            cout << -1;
            return 0;
        }
        if (x > 0 && y > 0) {
            quadrant1++;
        }
        else if (x < 0 && y > 0) {
            quadrant2++;
        }
        else if (x < 0 && y < 0) {
            quadrant3++;
        }
        else if (x > 0 && y < 0) {
            quadrant4++;
        }
    }


    long long count = quadrant1 * quadrant2 * quadrant3 + quadrant1 * quadrant2 * quadrant4 + quadrant1 * quadrant3 * quadrant4 + quadrant2 * quadrant3 * quadrant4;
    cout << count << endl;


    return 0;
}
