#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

vector<string>s;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool visited[1005][1005];
int f[1005][1005];

int dfs(int x, int y, int point) {
    visited[x][y] = true;
    int curr = 0;
    if (s[x][y] == 'x') {
        curr++;
    }

    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx >= 0 && newx < n &&
            newy >= 0 && newy < m &&
            !visited[newx][newy] && s[newx][newy] != '#') {
            curr += dfs(newx, newy, point);
        }
    }
    return curr;
}

signed main() {

    cin >> n >> m;
    s.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int>ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && s[i][j] != '#') {
                int curr = dfs(i, j, 0);
                if (curr != 0) ans.push_back(curr);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << " ";


    return 0;
}