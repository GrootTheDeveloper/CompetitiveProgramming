#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

vector<string>s;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool visited[1005][1005];
int f[1005][1005];

signed main() {

    cin >> n >> m;
    s.resize(n);
    memset(f, 1e9, sizeof(f));

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    f[0][0] = 0;
    visited[0][0] = true;
    queue<pair<int, int>> q;
    q.push({ 0,0 });

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;

        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx >= 0 && newx < n &&
                newy >= 0 && newy < m &&
                visited[newx][newy] == false && s[newx][newy] == '0') {

                f[newx][newy] = f[x][y] + 1;
                q.push({ newx, newy });
                visited[newx][newy] = true;
            }
        }
    }

    if (visited[n - 1][m - 1] == false) {
        cout << -1;
    }
    else cout << f[n - 1][m - 1];

    return 0;
}