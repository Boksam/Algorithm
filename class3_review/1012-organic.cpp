#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> farm;
vector<vector<bool>> visited;
int m, n, k;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};


bool isValid(int y, int x) {
  return 0 <= y && y < n && 0 <= x && x < m;
}

int bfs() {
  int answer = 0;
  queue<pair<int, int>> q;

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      if (farm[y][x] == 1 && !visited[y][x]) {
        answer++;
        visited[y][x] = true;
        q.push({y, x});
        while (!q.empty()) {
          int currY = q.front().first;
          int currX = q.front().second;
          q.pop();

          for (int i = 0; i < 4; i++) {
            int newY = currY + dy[i];
            int newX = currX + dx[i];
            if (isValid(newY, newX) && farm[newY][newX] == 1 && !visited[newY][newX]) {
              visited[newY][newX] = true;
              q.push({newY, newX});
            }
          }
        }
      }
    }
  }
  return answer;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> m >> n >> k;
    farm.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m));

    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      farm[y][x] = 1;
    }

    cout << bfs() << endl;
    farm.clear();
    visited.clear();
  }
}