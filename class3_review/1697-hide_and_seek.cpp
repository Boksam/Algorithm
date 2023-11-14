#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int N, K, ans = 1;
map<int, bool> visited;
queue<int> q;

int main() {
  cin >> N >> K;

  if (N == K) {
    cout << 0 << endl;
    return 0;
  }

  q.push(N);
  visited[N] = true;

  while (!q.empty()) {
    queue<int> tmpQ;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      int ps[3] = {curr-1, curr+1, curr*2};
      for (auto p : ps) {
        if (p < 0 || p > 100000) continue;

        if (!visited[p]) {
          if (p == K) {
            cout << ans << endl;
            return 0;
          }
          visited[p] = true;
          tmpQ.push(p);
        }
      }
    }
    q = tmpQ;
    ans++;
  }
  return 0;
}