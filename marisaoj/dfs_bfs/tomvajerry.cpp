#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int a, b;

vector<int>adj[100005];

signed main() {

    cin >> n >> m;
    cin >> a >> b;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<pair<int, int>> q;

    vector<int>stepJerry(n + 1, 0), stepTom(n + 1, 0);

    vector<bool> visited(n + 1, false);

    q.push({ a, 0 });

    stepJerry[a] = 0;

    visited[a] = true;

    while (!q.empty()) {

        auto cur = q.front();
        q.pop();

        auto u = cur.first;
        auto step = cur.second;

        for (auto v : adj[u]) {
            if (!visited[v]) {
                stepJerry[v] = step + 1;
                visited[v] = true;
                q.push({ v,stepJerry[v] });
            }
        }
    }

    q.push({ b, 0 });

    
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    stepTom[b] = 0;
    visited[b] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        auto u = cur.first;
        auto step = cur.second;

        for (auto v : adj[u]) {
            if (!visited[v]) {
                stepTom[v] = step + 1;
                visited[v] = true;
                q.push({ v,stepTom[v] });
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (stepJerry[i] <= stepTom[i]) count++;
    }

    cout << count;
    return 0;
}