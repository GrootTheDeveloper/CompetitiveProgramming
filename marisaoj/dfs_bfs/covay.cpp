#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<string>s;
bool visited[505][505];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y) {

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];

        if (newx >= 0 && newx < n && newy >= 0 && newy < m 
            && visited[newx][newy] == false) {
            dfs(newx, newy);
        }
    }
}

signed main() {

    cin >> n >> m;
    s.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'B') {
                visited[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                dfs(i, j);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                count++;
            }
        }
    }
    cout << count;

    return 0;
}