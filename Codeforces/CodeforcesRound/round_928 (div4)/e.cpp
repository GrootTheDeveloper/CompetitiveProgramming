#include <bits/stdc++.h>
#include <unordered_map>
#include "debug.h"
#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;
const int MOD = 1e9 + 7;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int k, n; cin >> n >> k;
        int odd_count = n / 2 + n % 2;
        int ans = 1;
        if (k <= odd_count) {
            ans = k * 2 - 1;
        }
        else {
            vector<int>size;
            size.push_back(odd_count);
            // so la bai con lai
            int remain = n - odd_count;
            // so la bai se day vao vector
            int left = remain / 2 + remain % 2;
            
            while (remain > 0) {
                size.push_back(left);
                remain -= left;
                left = remain / 2 + remain % 2;
            }
            int pow2 = 1;
            int count_index = 0;
            int position = 0;
            while (position < size.size() && k > count_index) {
                count_index += size[position];
                position++;
            }
            position--;

            pow2 = pow(2, position);
            int current = size[position];
            int fuck = count_index - k + 1;
            fuck = current - fuck + 1;

            ans = fuck * 2 - 1;
            ans = ans * pow2;
            
        }
        cout << ans << endl;
    }
}

