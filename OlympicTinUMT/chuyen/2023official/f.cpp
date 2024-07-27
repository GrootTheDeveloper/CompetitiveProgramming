#include<bits/stdc++.h>
using namespace std;
int main() {

    int n; cin >> n;

    vector<vector<int>> card(n);

    vector<bool> check(n, true);
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            card[i].push_back(x);
        }
        sort(card[i].begin(), card[i].end());
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && card[j].size() >= card[i].size() &&
                includes(card[j].begin(), card[j].end(), card[i].begin(), card[i].end())) {
                check[j] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << (check[i] ? "YES" : "NO") << endl;
    }


    return 0;
}
