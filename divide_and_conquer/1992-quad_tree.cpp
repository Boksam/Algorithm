#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<string>> pic;
string answer;

void divide_conquer(int y, int x, int size) {
    bool flag = true;
    string basis = pic[y][x];
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (pic[i][j] != basis) {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
    }

    if (flag) {
        answer += basis;
    }
    else {
        answer += "(";
        divide_conquer(y, x, size / 2);
        divide_conquer(y, x + size / 2, size / 2);
        divide_conquer(y + size / 2, x, size / 2);
        divide_conquer(y + size / 2, x + size / 2, size / 2);
        answer += ")";
    }
}

int main() {
    cin >> N;
    pic.resize(N, vector<string>(N));

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;

        for (int j = 0; j < N; j++) {
            pic[i][j] = line[j];
        }
    }

    divide_conquer(0, 0, N);

    cout << answer << endl;
    return 0;
}