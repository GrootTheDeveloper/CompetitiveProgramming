#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<int>adj[100005];

bool visited[100005];

int cnt = 0;

int previous[100005];

void print(int u) {
    vector<int> store;
    store.push_back(u);
    int v = previous[u];
    while (previous[v] != -1) {
        store.push_back(v);
        v = previous[v];
    }

    store.push_back(1);
    cout << store.size() - 1 << endl;
    for (int i = store.size() - 1; i >= 0; i--) {
        cout << store[i] << " ";
    }
    exit(0);
}

signed main() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;

    q.push(1);
    previous[1] = -1;

    vector<vector<int>> minDist;

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v])
            {
                previous[v] = u;
                visited[v] = true;
                q.push(v);
                if (v == n) {
                    previous[1] = -1;
                    print(v);
                }
            }
        }
    }

    return 0;
}