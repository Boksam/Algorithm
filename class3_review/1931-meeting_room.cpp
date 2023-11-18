#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
  pair<int, int> swapped_p1 = {p1.second, p1.first};
  pair<int, int> swapped_p2 = {p2.second, p2.first};
  return swapped_p1 < swapped_p2;
}

int N;
vector<pair<int, int>> meetings;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    pair<int, int> p;
    cin >> p.first >> p.second;
    meetings.push_back(p);
  }

  sort(meetings.begin(), meetings.end(), cmp);

  int t = 0, answer = 0;
  for (auto meeting : meetings) {
    if (t <= meeting.first) {
      answer++;
      t = meeting.second;
    }
  }

  cout << answer << endl;
}