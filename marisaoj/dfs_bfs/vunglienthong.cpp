#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<int>adj[100005];

bool visited[100005];

int cnt = 0;

void dfs(int u) {

    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}
signed main() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i); cnt++;
        }
    }
    cout << cnt;
    return 0;
}