#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int air_contact[100][100];
int grid[100][100];
bool visited[100][100];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool isValid(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void update_air() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int n_y = y + dy[i], n_x = x + dx[i];

            if (isValid(n_y, n_x)) {
                if (grid[n_y][n_x] == 1)
                    air_contact[n_y][n_x] += 1;
                else if (!visited[n_y][n_x]) {
                    q.push({n_y, n_x});
                    visited[n_y][n_x] = true;
                }
                    
            } 
        }
    }
}

bool update_cheese() {
    bool updated = false;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (grid[y][x] == 1 && air_contact[y][x] >= 2) {
                grid[y][x] = 0;
                updated = true;
            }
        }
    }
    return updated;
}

int solve() {
    int time = 0;
    bool flag = true;
    while (true) {
        memset(air_contact, 0, sizeof(air_contact));
        memset(visited, false, sizeof(visited));

        update_air();
        flag = update_cheese();

        if (flag)
            time += 1;
        else
            break;
    }
    return time;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];
    
    cout << solve() << endl;
}