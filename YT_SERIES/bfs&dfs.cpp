#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

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
  // BFS Treversal
  void bfs() {
    queue<int> q;
    vector<bool> vis(V, false);
    q.push(0);
    vis[0] = true;

    while (q.size() > 0) {
      int u = q.front();
      q.pop();
      cout << u << " ";
      for (int v : l[u]) {
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
    cout << endl;
  }
  // DFS traversal
  void dfsHelper(int u, vector<bool>& vis) {
    cout << u << ' ';
    vis[u] = true;
    for (int v : l[u]) {
      if (!vis[v]) {
        dfsHelper(v, vis);
      }
    }
  }
  void dfs() {
    int src = 0;
    vector<bool> vis(V, false);
    dfsHelper(src, vis);
    cout << endl;
  }
};

int main() {
  graph g(5);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  // g.addEdge(2,3);
  g.addEdge(2, 4);

  cout << "DFS Traversal: ";
  g.dfs();

  cout << "BFS Traversal: ";
  g.bfs();

  return 0;
}