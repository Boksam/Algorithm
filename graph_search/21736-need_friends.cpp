#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
pair<int, int> start;
vector<vector<char>> grid;
vector<vector<bool>> visited;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};


bool isValid(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}


int bfs() {
    int result = 0;
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (grid[y][x] == 'P') result++;

        for (int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];
            if (isValid(newY, newX) && !visited[newY][newX] && grid[newY][newX] != 'X') {
                q.push({newY, newX});
                visited[newY][newX] = true;
            }
        }
    }
    return result;
}


int main() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'I')
                start = {i, j};
        }
    }

    int result = bfs();
    
    if (result == 0) cout << "TT\n";
    else cout << result << '\n';

    return 0;
}