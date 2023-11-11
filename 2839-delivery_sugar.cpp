#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> dp(5001, 1e9);

int main() {
    cin >> n;

    dp[3] = 1;
    dp[5] = 1;

    for (int i = 6; i <= n; i++) {
        dp[i] = min(dp[i-3], dp[i-5]) + 1;
    }

    if (dp[n] == 1e9) cout << -1 << endl;
    else cout << dp[n] << endl;
    
    return 0;
}