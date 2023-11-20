#include <iostream>
#include <vector>
using namespace std;

vector<int64_t> dp(91);
int n;


int main() {
  cin >> n;
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;
  for (int i = 3; i <= 90; i++) {
    dp[i] = dp[i-2] + dp[i-1];
  }

  cout << dp[n] << endl;
}