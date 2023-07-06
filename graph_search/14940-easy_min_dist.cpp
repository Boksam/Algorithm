#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<vector<int>> ans;
pair<int, int> start;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};


bool isValid(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m && !visited[y][x];
}

void bfs() {
    int time = 0;
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        queue<pair<int, int>> tmpQ;

        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            
            q.pop();

            if (grid[y][x] == 0) continue;

            ans[y][x] = time;

            for (int i = 0; i < 4; i++) {
                int newY = y + dy[i];
                int newX = x + dx[i];

                if (isValid(newY, newX)) {
                    tmpQ.push({newY, newX});
                    visited[newY][newX] = true;
                }
            }
        }
        q = tmpQ;
        time++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 0 && !visited[i][j]) {
                ans[i][j] = -1;
            }
        }
    }
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m));
    ans.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2)
                start = {i, j};
        }
            
    bfs();
    
    for (auto line : ans) {
        for (auto n : line) {
            cout << n << " ";
        }
        cout << '\n';
    }

    return 0;
}