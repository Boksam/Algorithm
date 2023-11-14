#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
map<string, bool> heard;
vector<string> answer;

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string name;
    cin >> name;
    heard[name] = true;
  }
  for (int i = 0; i < M; i++) {
    string name;
    cin >> name;
    if (heard[name])
      answer.push_back(name);
  }

  cout << answer.size() << endl;
  sort(answer.begin(), answer.end());
  for (auto name : answer) cout << name << endl;
  return 0;
}