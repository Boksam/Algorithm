#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(1000001);
int n;

int main() {
  cin >> n;
  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;
  for (int i = 4; i < 1000001; i++) {
    if (i % 6 == 0) dp[i] = min(dp[i/3], min(dp[i/2], dp[i-1])) + 1;
    else if (i % 3 == 0) dp[i] = min(dp[i/3], dp[i-1]) + 1;
    else if (i % 2 == 0) dp[i] = min(dp[i/2], dp[i-1]) + 1;
    else dp[i] = dp[i-1] + 1;
  }
  cout << dp[n] << endl;
}