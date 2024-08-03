#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {

    int n, m;
    cin >> n >> m;

    if (n >= m) {
        cout << n - m;
        return 0;
    }
    bool visited[100005];
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({ n,0 });
    visited[n] = true;


    while (!q.empty()) {

        auto value = q.front().first;
        auto step = q.front().second;

        q.pop();

        auto u = value * 2;
        auto v = value - 1;

        if (u == m || v == m) {
            cout << step + 1;
            break;
        }

        if (!visited[u]) {
            q.push({ u,step + 1 });
        }
        if (!visited[v]) {
            q.push({ v,step + 1 });
        }

    }
    return 0;
}