#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k;
vector<int>adj[100005];
bool visited[100005];

signed main() {

    cin >> n >> m >> k;
    vector<int>p(k);
    for (int i = 0; i < k; i++) cin >> p[i];

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(n);
    vector<int>f(n + 1, 0);
    visited[n] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (visited[v] == false) {
                f[v] = f[u] + 1;
                q.push(v);
                visited[v] = true;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << f[p[i]] << " ";
    }

    return 0;
}