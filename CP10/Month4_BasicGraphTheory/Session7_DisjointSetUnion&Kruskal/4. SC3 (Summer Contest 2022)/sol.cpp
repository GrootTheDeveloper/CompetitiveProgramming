#include <iostream>
#include <vector>
#include <utility>       
#include <string>
int n, k, numQuery, par[100005];
long long value[100005];
int root[100005];
std::vector <std::pair <int, int> > adj[100005];
struct element {
  char c;
  int a, b, w;
};
std::vector <element> save;
void dfs(int u, int father, long long D) {
  par[u] = father;
  value[u] = D;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i].first;
    if (v == father) {
      continue;
    }
    dfs(v, u, D + (long long) adj[u][i].second);
  }
}

int findRoot(int u) {
  return root[u] = (root[u] == u ? u : findRoot(root[u]));
}

bool isSameSet(int u, int v) {
  int rootu = findRoot(u);
  int rootv = findRoot(v);
  return (rootu == rootv);
}

void unionSet(int u, int v) {
  int rootu = findRoot(u);
  int rootv = findRoot(v);
  root[rootu] = rootv;
}

int main() {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> numQuery; 
    save.clear();
    for (int query = 1; query <= numQuery; query++) {
      std::string oper;  
      std::cin >> oper;  
      if (oper == "!") {
        int a, b, w;
        std::cin >> a >> b >> w; 
        save.push_back((element) {oper[0], a, b, w});
      }
      else {
        int a, b;
        std::cin >> a >> b; 
        save.push_back((element) {oper[0], a, b, 0});
      }
    }
    for (int i = 1; i <= n; i++) {
      root[i] = i;
      adj[i].clear();
    }
    for (int i = 0; i < numQuery; i++) {
      element e = save[i];
      if (e.c == '!') {
        int u = e.a;
        int v = e.b;
        if (isSameSet(u, v) == false) {
          adj[u].push_back(std::make_pair(v, e.w));
          adj[v].push_back(std::make_pair(u, -e.w));
          unionSet(u, v);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      root[i] = i;
      par[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
      if (par[i] == -1) {
        dfs(i, -1, 0);
      }
    }
    for (int i = 0; i < numQuery; i++) {
      element e = save[i];
      int u = e.a;
      int v = e.b;
      char c = e.c;
      if (c == '?') {
        if (isSameSet(u, v) == false) {
          std::cout << "UNKNOWN" << std::endl; 
        }
        else {
          std::cout << value[v] - value[u] << std::endl; 
        }
      }
      else {
        unionSet(u, v);
      }
    }
  }
  return 0;
}