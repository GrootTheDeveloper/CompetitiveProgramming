#include <iostream>
#include <queue>
#include <vector>
int numTest; 
int n, m; 
std::vector <int> adj[400005]; 
int start, end; 
int dist[400005]; 

int main () {
  for (int i = 0; i <= 400000; i++) {
    dist[i] = -1; 
  }
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    std::vector <int> save; 
    for (int i = 1; i <= m; i++) {
      int u, v, color;
      std::cin >> u >> v >> color; 
      save.push_back(u);
      save.push_back(color + n);   
      save.push_back(v);        
      adj[u].push_back(color + n); 
      adj[color + n].push_back(u); 
      adj[v].push_back(color + n); 
      adj[color + n].push_back(v);
    }
    std::cin >> start >> end;
    std::queue <int> myqueue; 
    dist[start] = 0; 
    myqueue.push(start); 
    while (myqueue.empty() == false) {
      int u = myqueue.front();
      myqueue.pop(); 
      for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          myqueue.push(v); 
        }
      }
    }
    std::cout << dist[end] / 2 << std::endl; 
    while (save.empty() == false) {
      adj[save.back()].clear(); 
      dist[save.back()] = -1; 
      save.pop_back(); 
    }
  }
  return 0; 
}