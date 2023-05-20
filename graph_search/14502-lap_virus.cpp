#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> selected;

int maximum = 0;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool isValid(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

int BFS() {
    int safeArea = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> tmpGrid = grid;
    vector<vector<bool>> visited = vector(N, vector<bool>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newY = currY + dy[i];
            int newX = currX + dx[i];

            if (isValid(newY, newX) && !visited[newY][newX] && tmpGrid[newY][newX] == 0) {
                tmpGrid[newY][newX] = 2;
                visited[newY][newX] = true;
                q.push({newY, newX});
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (tmpGrid[i][j] == 0)
                safeArea++;
    
    return safeArea;
}

void solve(int n) {
    if (n == 3) {
        maximum = max(maximum, BFS());
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 0 && !selected[i][j]) {
                grid[i][j] = 1;
                selected[i][j] = true;

                solve(n + 1);

                grid[i][j] = 0;
                selected[i][j] = false;
            }
        }
    }

}

int main() {
    cin >> N >> M;
    
    grid.resize(N, vector<int>(M));
    selected.resize(N, vector<bool>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];

    solve(0);

    cout << maximum << endl;
}