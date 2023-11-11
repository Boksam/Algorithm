#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main() {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	
	int N;
	cin >> N;

	for (int i = 5; i <= N; i++) {
		if (i % 3 == 0 && i % 2 == 0) {
			dp[i] = 1 + min(dp[i / 3], dp[i / 2]);
		}
		else if (i % 3 == 0) {
			dp[i] = 1 + min(dp[i / 3], dp[i - 1]);
		}
		else if (i % 2 == 0) {
			dp[i] = 1 + min(dp[i / 2], dp[i - 1]);
		}
		else {
			dp[i] = 1 + dp[i - 1];
		}
	}

	cout << dp[N];
	return 0;
}