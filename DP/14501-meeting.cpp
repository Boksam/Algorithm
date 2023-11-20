#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<pair<int, int>> schedule;
map<int, vector<int>> m;
vector<int> dp;
int n;

int main() {
  cin >> n;
  schedule.resize(n+1);
  dp.resize(n+2);

  for (int i = 1; i <= n; i++) {
    cin >> schedule[i].first >> schedule[i].second;
    m[i + schedule[i].first].push_back(i);
  }

  for (int i = 1; i <= n+1; i++) {
    dp[i] = dp[i-1];
    if (!m[i].empty()) {
      int maxP = 0;
      for (auto t : m[i]) {
        maxP = max(maxP, dp[t] + schedule[t].second);
      }
      dp[i] = max(dp[i], maxP);
    }
  }

  cout << dp[n+1] << endl;
  return 0;
}

/*
  1   2   3   4   5   6   7
  0   0   0   0   0   0   0
  0   0   10  0   0   0   0
  0   0   10  0   0   20  0


  1   2   3   4   5   6   7
          1   4       2
          3           5
*/