#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<string> maze;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};


bool isValid(int y, int x) {
  return 0 <= y && y < N && 0 <= x && x < M;
}


int bfs() {
  vector<vector<bool>> visited(N, vector<bool>(M));
  queue<pair<int, int>> q;
  int t = 1;
  q.push({0, 0});
  visited[0][0] = true;
  
  while (!q.empty()) {
    queue<pair<int, int>> tmpQ;
    while (!q.empty()) {
      int currY = q.front().first;
      int currX = q.front().second;
      q.pop();

      if (currY == N-1 && currX == M-1) return t;

      for (int i = 0; i < 4; i++) {
        int newY = currY + dy[i];
        int newX = currX + dx[i];
        if (isValid(newY, newX) && !visited[newY][newX] && maze[newY][newX] == '1') {
          tmpQ.push({newY, newX});
          visited[newY][newX] = true;
        }
      }
    }
    q = tmpQ;
    t++;
  }
}


int main() {
  cin >> N >> M;
  maze.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> maze[i];
  }

  cout << bfs() << endl;
  return 0;
}