#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int r, c, t;
vector<vector<int>> grid;
vector<pair<int, int>> cleaner;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int upper_dy[] = {0, -1, 0, 1};
int upper_dx[] = {1, 0, -1, 0};
int lower_dy[] = {0, 1, 0, -1};
int lower_dx[] = {1, 0, -1, 0};


bool isValid(int y, int x) {
    return 0 <= y && y < r && 0 <= x && x < c;
}


void diffusion() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] > 0) {
                int new_dust = grid[i][j] / 5;
                for (int i = 0; i < 4; i++) {
                    int newY = i + dy[i];
                    int newX = j + dx[i];

                    if (isValid(newY, newX) && grid[newY][newX] != -1) {
                        grid[newY][newX] += new_dust;
                    }
                }
            }
        }
    }
}


void cleaning() {
    int upperY = cleaner[0].first;
    int upperX = cleaner[0].second;

    for (int i = 0; i < 4; i++) {
        
        while (true) {
            upperY += upper_dy[i];
            upperX += upper_dx[i];
            if (!isValid(upperY, upperX)) break;

            int prev_y = upperY - upper_dy[i];
            int prev_x = upperX - upper_dx[i];
            if (grid[prev_y][prev_x] == -1) continue;

            grid[upperY][upperX] = grid[prev_y][prev_x];
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
    
    if (cleaner[0].first > cleaner[1].second) swap(cleaner[0], cleaner[1]);

    while (t--) {
        diffusion();
        cleaning();

    }
}