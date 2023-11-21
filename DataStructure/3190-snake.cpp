/*
  뱀을 deque에 저장 (front: 머리)
  board 0: 아무것도 없음, 1: 사과, 2: 뱀 몸통
  머리가 되는 좌표 탐색
    만약 벽이면 return
    만약 자기 몸에 닿으면 return
  머리를 늘린다
  머리에 사과가 없으면 꼬리 pop_back  
*/

#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;


int N, K, L;
vector<vector<int>> board;
deque<pair<int, int>> snake;
queue<pair<int, string>> turns;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};


bool isWall(int y, int x) {
  return !(0 < y && y <= N && 0 < x && x <= N);
}

bool isSnake(int y, int x) {
  return board[y][x] == 2;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  board.resize(N+1, vector<int>(N+1));
  snake.push_front({1, 1});
  for (int i = 0; i < K; i++) {
    int y, x;
    cin >> y >> x;
    board[y][x] = 1;
  }
  cin >> L;
  for (int i = 0; i < L; i++) {
    string t, d;
    cin >> t >> d;
    turns.push({stoi(t), d});
  }

  int t = 0, y = 1, x = 1, dir = 0;
  while (true) {
    if (t == turns.front().first) {   // 방향 바꾸기
      if (turns.front().second == "L") {
        if (dir == 0) dir = 3;
        else dir -= 1; 
      }
      else {
        if (dir == 3) dir = 0;
        else dir += 1;
      }
      turns.pop();
    }
    
    y += dy[dir];   // 머리가 될 좌표
    x += dx[dir];
    t++;

    if (!isWall(y, x) && !isSnake(y, x)) {
      if (board[y][x] != 1) {   // 사과가 없으면
        pair<int, int> tail = snake.back();
        board[tail.first][tail.second] = 0;
        snake.pop_back();
      }
      snake.push_front({y, x});
      board[y][x] = 2;
    }
    else {
      cout << t << endl;
      break;
    }
  }
  return 0;
}