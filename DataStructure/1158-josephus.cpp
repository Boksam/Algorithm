#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
queue<int> q;
vector<int> answer;

int main() {
  ios::sync_with_stdio(false);
  cout.tie(NULL);

  cin >> N >> K;
  for (int i = 1 ; i <= N; i++)
    q.push(i);
  
  while (answer.size() != N) {
    int turn = 1;
    while (turn != K) {
      int front = q.front();
      q.pop();
      q.push(front);
      turn++;
    }
    answer.push_back(q.front());
    q.pop();
  }

  cout << "<";
  for (int i = 0; i < N; i++) {
    if (i == N-1) cout << answer[i];
    else cout << answer[i] << ", ";
  }
  cout << ">\n";
  return 0;
}