#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int N, M, minBacon = 1e9, ans = 0;
map<int, vector<int>> friends;

void getInput() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int p1, p2;
    cin >> p1 >> p2;
    friends[p1].push_back(p2);
    friends[p2].push_back(p1);
  }
}


int getBacon(int person) {
  queue<int> q;
  map<int, bool> visited;
  q.push(person);

  int bacon = 0, d = 0;
  while (!q.empty()) {
    queue<int> tmp_q;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      if (visited[curr]) continue;
      visited[curr] = true;
      bacon += d;

      for (auto it : friends[curr]) {
        if (!visited[it]) tmp_q.push(it);
      }
    }
    d++;
    q = tmp_q;
  }
  return bacon;
}

int main() {
  getInput();
  
  for (int i = 1; i <= N; i++) {
    int newBacon = getBacon(i);
    if (minBacon > newBacon) {
      minBacon = newBacon;
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}