#include <iostream>
#include <vector>
using namespace std;

vector<int> stairs;
vector<int> dp;
int n;

int main() {
  cin >> n;
  stairs.resize(n+1);
  dp.resize(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> stairs[i];
  }

  dp[0] = 0;
  dp[1] = stairs[1];
  dp[2] = stairs[1] + stairs[2];
  
  for (int i = 3; i <= n; i++) {
    dp[i] = max(dp[i-2] + stairs[i], dp[i-3] + stairs[i-1] + stairs[i]);
  }

  cout << dp[n] << endl;
  return 0;
}