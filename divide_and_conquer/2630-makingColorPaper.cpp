#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> paper;
int blue = 0, white = 0;

void DAC(int y, int x, int len) {
    int base = paper[y][x];

    bool flag = true;
    for (int i = y; i < y + len; i++) {
        for (int j = x; j < x + len; j++) {
            if (paper[i][j] != base) {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
    }

    if (!flag) {
        DAC(y, x, len / 2);
        DAC(y, x + len / 2, len / 2);
        DAC(y + len / 2, x, len / 2);
        DAC(y + len / 2, x + len / 2, len / 2);
    }
    else {
        if (base == 0)
            white++;
        else
            blue++;
    }
}

int main() {
    int N;
    cin >> N;

    paper.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];

    DAC(0, 0, N);

    cout << white << '\n' << blue << endl;
}