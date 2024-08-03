#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k;
vector<int>adj[100005];
bool visited[100005];
bool colors[100005];

void dfs(int u, bool color) {
    visited[u] = true;

    for (auto v : adj[u]) {
        if (!visited[v]) {
            colors[v] = !colors[u];

            dfs(v, colors[v]);
        }
    }
}

signed main() {

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool color = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, color);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto v : adj[i]) {
            if (colors[v] == colors[i]) {
                cout << "NO";
                exit(0);
            }
        }
        
    }
    cout << "YES";
    return 0;
}