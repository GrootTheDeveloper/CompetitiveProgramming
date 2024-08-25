#include <bits/stdc++.h>
using namespace std;
#define int long long

const int oo = LLONG_MAX;

vector<pair<int, int>> adj[200005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

int dist[200005];
int pre[200005];

void dijkstra(int start) {
	dist[start] = 0;
	pq.push({0,start});

	while (!pq.empty()) {
		auto element = pq.top();
		pq.pop();

		int weight = element.first;
		int curr = element.second;

		if (weight != dist[curr]) continue;

		for (auto v : adj[curr]) {
			if (dist[v.first] > dist[curr] + v.second) {
				dist[v.first] = dist[curr] + v.second;
				pq.push({ dist[v.first], v.first });
				pre[v.first] = curr;
			}
		}
	}

}


signed main() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}

	for (int i = 0; i < 200005; i++) dist[i] = oo;

	dijkstra(1);
	vector<int>ans;
	if (dist[n] == oo) {
		cout << -1;
		return 0;
	}
	int now = n;
	ans.push_back(n);
	while (now != 1) {
		now = pre[now];
		ans.push_back(now);
	}
	reverse(ans.begin(), ans.end());
	cout << dist[n] << endl;
	for (auto i : ans) {
		cout << i << " ";
	}
}
