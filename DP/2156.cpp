#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int N;
	cin >> N;

	vector<int> wine(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> wine[i];
	}

	vector<int> dp(N + 1);
	dp[1] = wine[1];
	dp[2] = dp[1] + wine[2];
	dp[3] = max(dp[1] + wine[3], max(dp[2], wine[2] + wine[3]));

	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], max(dp[i - 2] + wine[i], dp[i - 1]));
	}
	
	cout << dp[N];
	return 0;
}