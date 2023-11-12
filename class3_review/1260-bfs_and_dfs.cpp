#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

int n, m, startPos;
map<int, set<int>> edges;


void getInputs() {
  cin >> n >> m >> startPos;
  for (int i = 0; i < m; i++) {
    int p1, p2;
    cin >> p1 >> p2;
    edges[p1].insert(p2);
    edges[p2].insert(p1);
  }
}


void dfs() {
  stack<int> s;
  map<int, bool> visited;
  s.push(startPos);

  while (!s.empty()) {
    int curr = s.top();
    s.pop();
    if (visited[curr]) continue;
    cout << curr << " ";
    visited[curr] = true;

    for (set<int>::reverse_iterator iter = edges[curr].rbegin(); iter != edges[curr].rend(); iter++) {
      s.push(*iter);
    }
  }
  cout << endl;
}


void bfs() {
  queue<int> q;
  map<int, bool> visited;
  q.push(startPos);

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    if (visited[curr]) continue;
    cout << curr << " ";
    visited[curr] = true;

    for (auto node : edges[curr]) {
      q.push(node);
    }
  }
  cout << endl;
}

int main() {
  getInputs();
  dfs();
  bfs();
  return 0;
}