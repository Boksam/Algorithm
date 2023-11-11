#include <iostream>
#include <vector>
using namespace std;

int N, M;
int x1, x2, y1, y2;
vector<vector<int>> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    dp.resize(N+1, vector<int>(N+1));

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> dp[i][j];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dp[i][j] += dp[i][j-1];
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dp[j][i] += dp[j-1][i];

    while (M--) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << dp[y2][x2] - dp[y2][x1-1] - dp[y1-1][x2]  + dp[y1-1][x1-1] << '\n'; 
    }
}