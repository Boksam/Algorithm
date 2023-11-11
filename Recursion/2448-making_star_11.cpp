#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<char>> map;

void star(int n, int y, int x) {
    if (n == 3) {
        map[y][x] = '*';
        map[y+1][x-1] = '*';
        map[y+1][x+1] = '*';
        map[y+2][x-2] = '*';
        map[y+2][x-1] = '*';
        map[y+2][x] = '*';
        map[y+2][x+1] = '*';
        map[y+2][x+2] = '*';
        return;
    }

    star(n / 2, y, x);
    star(n / 2, y + n / 2, x - n / 2);
    star(n / 2, y + n / 2, x + n / 2);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int width = 5 * (N / 3) + (N / 3 - 1);
    int height = N;

    map.resize(height, vector<char>(width, ' '));

    

    star(N, 0, width / 2);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            cout << map[i][j];
        cout << '\n';
    }
    
}