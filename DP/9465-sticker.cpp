#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v1;
vector<int> v2;

int solve(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(2));

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = v1[0];
    dp[1][1] = v2[0];

    for (int i = 2; i < n + 1; i++)
    {
        dp[i][0] = max(dp[i - 1][1], max(dp[i - 2][0], dp[i - 2][1])) + v1[i - 1];
        dp[i][1] = max(dp[i - 1][0], max(dp[i - 2][1], dp[i - 2][0])) + v2[i - 1];
    }

    return max(dp[n][0], dp[n][1]);
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        v1.clear();
        v2.clear();
        int n;
        cin >> n;
        v1.resize(n);
        v2.resize(n);
        for (int j = 0; j < n; j++)
            cin >> v1[j];
        for (int j = 0; j < n; j++)
            cin >> v2[j];

        cout << solve(n) << '\n';
    }
}