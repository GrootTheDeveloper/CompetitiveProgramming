#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<int>adj[100005];

bool visited[100005];

int cnt = 0;

signed main() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;

    q.push(1);
    vector<int> f(1e5 + 1, -1);

    f[1] = 0;

    while (!q.empty()) {

        int u = q.front();
        q.pop();



        for (int v : adj[u]) {
            if (!visited[v])
            {
                f[v] = f[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << f[i] << " ";
    }
    return 0;
}