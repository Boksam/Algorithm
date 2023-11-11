#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int r, c, t;
vector<vector<int>> grid;
vector<pair<int, int>> cleaner;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int u_dy[4] = {0, -1, 0, 1};
int u_dx[4] = {1, 0, -1, 0};
int l_dy[4] = {0, 1, 0, -1};
int l_dx[4] = {1, 0, -1, 0};


bool isValid(int y, int x) {
    return 0 <= y && y < r && 0 <= x && x < c;
}

void defusing() {
    queue<pair<int, int>> q;
    vector<vector<int>> toAdd = vector(r, vector<int>(c));
    vector<vector<int>> toSub= vector(r, vector<int>(c));

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (grid[y][x] > 0) {
                int newDust = grid[y][x] / 5;
                for (int i = 0; i < 4; i++) {
                    int newY = y + dy[i];
                    int newX = x + dx[i];
                    if (isValid(newY, newX) && grid[newY][newX] != -1) {
                        toAdd[newY][newX] += newDust;
                        toSub[y][x] -= newDust;
                    }
                }
            }
        }
    }

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            grid[y][x] += toAdd[y][x];
            grid[y][x] += toSub[y][x];
        }
    }
}

void cleaning() {
    int currY = cleaner[0].first;
    int currX = cleaner[0].second;
    int prevY = cleaner[0].first;
    int prevX = cleaner[0].second;

    int prevDust = 0;

    for (int i = 0; i < 4; i++) {
        while (true) {
            currY += u_dy[i];
            currX += u_dx[i];

            if (!isValid(currY, currX)) {
                currY -= u_dy[i];
                currX -= u_dx[i];
                prevY = currY;
                prevX = currX;
                break;
            }

            if (grid[currY][currX] == -1) break;

            int tmp = grid[currY][currX];
            grid[currY][currX] = prevDust;
            prevDust = tmp;

            prevY = currY;
            prevX = currX;
        }
    }

    currY = cleaner[1].first;
    currX = cleaner[1].second;
    prevY = cleaner[1].first;
    prevX = cleaner[1].second;

    prevDust = 0;

    for (int i = 0; i < 4; i++) {
        while (true) {
            currY += l_dy[i];
            currX += l_dx[i];

            if (!isValid(currY, currX)) {
                currY -= l_dy[i];
                currX -= l_dx[i];
                prevY = currY;
                prevX = currX;
                break;
            }

            if (grid[currY][currX] == -1) break;

            int tmp = grid[currY][currX];
            grid[currY][currX] = prevDust;
            prevDust = tmp;

            prevY = currY;
            prevX = currX;
        }
    }
}

int main() {
    cin >> r >> c >> t;
    grid.resize(r, vector<int>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == -1)
                cleaner.push_back({i, j});
        }
    }

    if (cleaner[0].first > cleaner[1].first)
        swap(cleaner[0], cleaner[1]);

    while (t--) {
        defusing();
            
        cleaning();
    }

    int result = 0;
    for (int y = 0; y < r; y++)
        for (int x = 0; x < c; x++)
            if (grid[y][x] > 0)
                result += grid[y][x]; 

    cout << result << endl;
    return 0;
}