#include <iostream>
#include <list>
#include <vector>
using namespace std;
// Detect Cycle with undirected graph  -->Using DFS

class graph {
  int V;
  list<int>* l;

 public:
  graph(int v) {
    this->V = v;
    l = new list<int>[V];
  }
  void addEdge(int u, int v) {
    l[u].push_back(v);
    l[v].push_back(u);
  }
  // DFS traversal
  //  void dfsHelper(int u,vector<bool>&vis){
  //      cout<<u<<" ";
  //      vis[u] = true;

  //     for(int v:l[u]){
  //         if(!vis[v]){
  //             dfsHelper(v,vis);
  //         }
  //     }
  // }
  // void dfs(){
  //       int src = 0;
  //       vector<bool>vis(V,false);
  //       dfsHelper(src,vis);
  //       cout<<endl;
  //         }
  bool isCycleDFS(int src, int par, vector<bool>& vis) {
    vis[src] = true;
    list<int> neighbour = l[src];

    for (int v : neighbour) {
      if (!vis[v]) {
        if (isCycleDFS(v, src, vis)) {
          return true;
        }
      } else if (v != par) {
        return true;
      }
    }
    return false;
  }
  bool isCycle() {
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        if (isCycleDFS(i, -1, vis)) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  graph g(5);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(1, 2);
  g.addEdge(3, 4);
  // g.addEdge(0,1);
  cout << g.isCycle() << endl;
  // g.dfs();

  return 0;
}

// Detect Cycle with undirected graph -->Using BFS

#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class graph {
  int V;
  list<int>* l;

 public:
  graph(int V) {
    this->V = V;
    l = new list<int>[V];
  }
  void addEdge(int u, int v) {
    l[u].push_back(v);
    l[v].push_back(u);
  }
  bool isCycleUndirBFS(int src, vector<bool>& vis) {
    queue<pair<int, int>> q;

    q.push({src, -1});
    vis[src] = true;

    while (q.size() > 0) {
      int u = q.front().first;
      int parU = q.front().second;
      q.pop();

      list<int> neighbour = l[u];

      for (int v : neighbour) {
        if (!vis[v]) {
          q.push({v, u});
          vis[v] = true;
        } else if (v != parU) {  // cycle condition
          return true;
        }
      }
    }
    return false;
  }
  bool isCycle() {
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        if (isCycleUndirBFS(i, vis)) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  graph g(5);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  // g.addEdge(1,2);
  g.addEdge(3, 4);
  cout << g.isCycle() << endl;

  return 0;
}

// Cycle Detect Directed Graph -->Using DFS

#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class graph {
  int V;
  list<int>* l;

 public:
  graph(int V) {
    this->V = V;
    l = new list<int>[V];
  }
  void addEdge(int u, int v) {
    l[u].push_back(v);  // only Directed Graph
  }
  // Cycle detection
  bool isCycleisDirected(int curr, vector<bool>& vis, vector<bool>& recPath) {
    vis[curr] = true;
    recPath[curr] = true;
    for (int v : l[curr]) {
      if (!vis[v]) {
        if (isCycleisDirected(v, vis, recPath)) {
          return true;
        }
      } else if (recPath[v]) {
        return true;
      }
    }
    recPath[curr] = false;
    return false;
  }
  bool isCycle() {
    vector<bool> vis(V, false);
    vector<bool> recPath(V, false);

    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        if (isCycleisDirected(i, vis, recPath)) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  graph g(4);

  g.addEdge(1, 0);
  g.addEdge(0, 2);
  g.addEdge(2, 3);
  // g.addEdge(3,0);
  cout << g.isCycle() << endl;

  return 0;
}

// Topological Sort --> Using DFS
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class graph {
  int V;
  list<int>* l;

 public:
  graph(int V) {
    this->V = V;
    l = new list<int>[V];
  }
  void addEdge(int u, int v) {
    l[u].push_back(v);  // only Directed Graph
  }

  void dfs(int curr, vector<bool>& vis, stack<int>& s) {
    vis[curr] = true;

    for (int v : l[curr]) {
      if (!vis[v]) {
        dfs(v, vis, s);
      }
    }
    s.push(curr);
  }
  void topoSort() {
    vector<bool> vis(V, false);
    stack<int> s;

    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        dfs(i, vis, s);
      }
    }
    while (s.size() > 0) {
      cout << s.top() << " ";
      s.pop();
    }
    cout << endl;
  }
};

int main() {
  graph g(6);

  g.addEdge(3, 1);
  g.addEdge(2, 3);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(5, 0);
  g.addEdge(5, 3);
  g.topoSort();

  return 0;
}