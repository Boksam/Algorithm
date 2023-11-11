#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int target, brokeCnt, answer;
vector<bool> broken(10);


bool possible(int n) {
  string s = to_string(n);
  for (auto c : s)
    if (broken[c - '0']) return false;
  return true;
}

int main() {
  cin >> target >> brokeCnt;
  for (int i = 0; i < brokeCnt; i++) {
    int tmp;
    cin >> tmp;
    broken[tmp] = true;
  }

  answer = abs(target - 100);

  for (int i = 0; i < 1000000; i++) {
    if (possible(i)) {
      answer = min(answer, int(abs(target - i) + to_string(i).length()));
    }
  }

  cout << answer << endl;
}