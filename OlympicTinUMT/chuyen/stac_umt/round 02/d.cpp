#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;

vector<int> adj[200005];

bool visited[200005];

int maxSCC_index;

void dfs(int u) {
	visited[u] = true;
	maxSCC_index = max(u, maxSCC_index);

	for (auto v : adj[u]) {
		if (!visited[v]) dfs(v);
	}
}

signed main() {
	int t; cin >> t;
	while (t--) {

		int n, m; cin >> n >> m;

		for (int i = 1; i <= 2e5; i++) {
			visited[i] = false;
			adj[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		maxSCC_index = -1;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				if (i < maxSCC_index)
					res++;
				dfs(i);
			}
		}
		cout << res << endl;
	}
}
