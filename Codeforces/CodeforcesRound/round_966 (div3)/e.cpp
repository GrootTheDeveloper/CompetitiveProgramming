#include <bits/stdc++.h>
#include <unordered_map>
#define int long long
#define yes cout << "yes"
#define no cout << "no"
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;

    while (t--) {

        int n, m, k, w;
        cin >> n >> m >> k;
        cin >> w;

        vector<int> heights(w);
        for (int i = 0; i < w; i++) {
            cin >> heights[i];
        }

        sort(heights.begin(), heights.end(), greater<int>());

        vector<vector<int>> freq(n, vector<int>(m, 0));

        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j <= m - k; j++) {
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        freq[x][y]++;
                    }
                }
            }
        }

        vector<int> all_freq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                all_freq.push_back(freq[i][j]);
            }
        }
        sort(all_freq.rbegin(), all_freq.rend());

        int ans = 0;
        for (int i = 0; i < min((int)all_freq.size(), w); i++) {
            ans += heights[i] * all_freq[i];
        }

        cout << ans << endl;


    }

    return 0;
}
