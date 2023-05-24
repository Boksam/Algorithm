#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> grid;
vector<vector<int>> dp_horizontal;
vector<vector<int>> dp_vertical;
vector<vector<int>> dp_diagnal;
vector<vector<int>> dp;

int main() {
    cin >> N;
    grid.resize(N + 1, vector<int>(N + 1));
    dp_horizontal.resize(N + 1, vector<int>(N + 1));
    dp_vertical.resize(N + 1, vector<int>(N + 1));
    dp_diagnal.resize(N + 1, vector<int>(N + 1));
    dp.resize(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> grid[i][j];
    
    dp_horizontal[1][2] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 3; j <= N; j++) {

            if (grid[i][j] == 1) {
                dp_horizontal[i][j] = 0;
                dp_vertical[i][j] = 0;
                dp_diagnal[i][j] = 0;
            }
            else {
                dp_horizontal[i][j] = dp_horizontal[i][j-1] + dp_diagnal[i][j-1];
                dp_vertical[i][j] = dp_vertical[i-1][j] + dp_diagnal[i-1][j];

                if (grid[i-1][j] == 0 && grid[i][j-1] == 0)
                    dp_diagnal[i][j] = dp_horizontal[i-1][j-1] + dp_vertical[i-1][j-1] + dp_diagnal[i-1][j-1];
                else
                    dp_diagnal[i][j] = 0;
            }
            dp[i][j] = dp_horizontal[i][j] + dp_vertical[i][j] + dp_diagnal[i][j];
        }
    }

    cout << dp[N][N] << endl;
    return 0;
}