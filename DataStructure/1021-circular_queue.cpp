#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, M, answer = 0;
deque<int> d1;
deque<int> d2;
vector<int> targets;

int main() {
  cin >> N >> M;
  for (int i = 0 ; i < M; i++) {
    int target;
    cin >> target;
    targets.push_back(target);
  }
  for (int i = 1; i <= N; i++) {
    d1.push_back(i);
    d2.push_back(i);
  }

  for (auto target : targets) {
    int t = 0;
    while (true) {
      if (d1.front() == target) {
        d1.pop_front();
        d2 = d1;
        break;
      }
      if (d2.front() == target) {
        d2.pop_front();
        d1 = d2;
        break;
      }
      d1.push_back(d1.front());
      d1.pop_front();
      d2.push_front(d2.back());
      d2.pop_back();
      t++;
    }
    answer += t;
  }

  cout << answer << endl;
  return 0;
}