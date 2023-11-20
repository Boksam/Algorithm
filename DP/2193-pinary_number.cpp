#include <iostream>
#include <vector>
using namespace std;

vector<pair<int64_t, int64_t>> dp(91);
int n;


int main() {
  cin >> n;
  dp[1] = {0, 1};
  dp[2] = {1, 0};
  for (int i = 3; i <= 90; i++) {
    dp[i].first = dp[i-1].first + dp[i-1].second;
    dp[i].second = dp[i-1].first;
  }
  cout << dp[n].first + dp[n].second << endl;
  return 0;
}

/*
  0으로 끝나면 0 or 1
  1로 끝나면 무조건 0

  0 = 이전0 + 이전 1
  1 = 이전0
  
  1 = {0, 1}
  10 = {1, 0}
  101 100 = {1, 1}
  1000 1001 1010 = {2, 1}
*/