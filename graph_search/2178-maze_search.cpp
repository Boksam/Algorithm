#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M;
vector<vector<int>> maze;
vector<vector<int>> cost;
vector<vector<bool>> visited;

bool isValid(int y, int x) {
    if (y < 0 || y > N - 1 || x < 0 || x > M - 1 || maze[y][x] == 0)
        return false;
    else
        return true;
}

int DFS() {
    stack<pair<int, int>> myStack;
    myStack.push({0, 0});
    visited[0][0] = true;

    int diffX[4] = {0, 0, -1, 1};
    int diffY[4] = {1, -1, 0, 0};

    while (!myStack.empty()) {
        int currY = myStack.top().first;
        int currX = myStack.top().second;
        myStack.pop();

        for (int i = 0; i < 4; i++) {
            int newY = currY + diffY[i];
            int newX = currX + diffX[i];
            if (isValid(newY, newX)) {
                if (visited[newY][newX]) {
                    if (cost[newY][newX] > cost[currY][currX] + 1) {
                        cost[newY][newX] = cost[currY][currX] + 1;
                        myStack.push({newY, newX});
                    }
                }
                else {
                    cost[newY][newX] = cost[currY][currX] + 1;
                    visited[newY][newX] = true;
                    myStack.push({newY, newX});
                }
            }
        }
    }
    return cost[N-1][M-1];
}


int main() {
    cin >> N >> M;

    maze.resize(N, vector<int>(M));
    cost.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M));

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            maze[i][j] = line[j] - '0';
        }
    }

    cost[0][0] = 1;

    cout << DFS() << endl;
    return 0;
}