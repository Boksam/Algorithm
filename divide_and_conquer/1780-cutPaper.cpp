#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;
vector<vector<int>> paper;
map<int, int> myCount;

void DQ(int y, int x, int len) {
    int base = paper[y][x];
    bool isAllSame = true;

    for (int i = y; i < y + len; i ++) {
        for (int j = x; j < x + len; j++) {
            if (paper[i][j] != base) {
                isAllSame = false;
                break;
            }
        }
        if (!isAllSame)
            break;
    }

    if (isAllSame) {
        myCount[base]++;
    }
    else {
        for (int i = y; i < y + len; i += len / 3) {
            for (int j = x; j < x + len; j += len / 3) {
                DQ(i, j, len / 3);
            }
        }
    }
}

int main() {
    cin >> N;
    paper.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];
    
    DQ(0, 0, N);

    cout << myCount[-1] << '\n' << myCount[0] << '\n' << myCount[1] << '\n';
}