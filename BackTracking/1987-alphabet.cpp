#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int r, c;
vector<vector<char>> grid;
vector<vector<int>> record;
bool visited[200];
int ans = 0;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool isValid(int y, int x) {
    return 0 <= y && y < r && 0 <= x && x < c;
}

void backTracking(int y, int x, int n) {

    ans = max(ans, n);

    for (int i = 0; i < 4; i++) {
        int newY = y + dy[i];
        int newX = x + dx[i];

        if (isValid(newY, newX) && !visited[grid[newY][newX]]) {
            visited[grid[newY][newX]] = true;
            
            backTracking(newY, newX, n + 1);

            visited[grid[newY][newX]] = false;;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> r >> c;
    grid.resize(r, vector<char>(c));
    record.resize(r, vector<int>(c, -1));

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];

    visited[grid[0][0]] = true;
    backTracking(0, 0, 1);

    cout << ans << endl;
}