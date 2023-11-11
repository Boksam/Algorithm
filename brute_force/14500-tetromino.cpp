#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> paper;
vector<vector<bool>> visited;
int N = 0, M = 0, answer = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};


bool isValid(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}


void bruteForce(int size, int y, int x, int currSum) {
    if (size == 4) {
        if (answer < currSum)
            answer = currSum;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int newY = y + dy[i];
        int newX = x + dx[i];
        if (isValid(newY, newX) && !visited[newY][newX]) {
            visited[newY][newX] = true;
            bruteForce(size + 1, newY, newX, currSum + paper[newY][newX]);
            visited[newY][newX] = false;
        }
    }
}

void checkFuckYou() {
    // ㅏ check
    int newSum = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            newSum = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+1][j+1];
            answer = max(answer, newSum);
        }
    }

    // ㅜ check
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            newSum = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j+1];
            answer = max(answer, newSum);
        }
    }

    // ㅓ check
    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j < M - 1; j++) {
            newSum = paper[i][j] + paper[i-1][j+1] + paper[i][j+1] + paper[i+1][j+1];
            answer = max(answer, newSum);
        }
    }

    // ㅗ check
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M - 2; j++) {
            newSum = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i-1][j+1];
            answer = max(answer, newSum);
        }
    }
}


int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    paper.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
        }
    }

    vector<pair<int, int>> tet;     // y, x 좌표 저장

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            bruteForce(0, i, j, 0);

    checkFuckYou();
    
    cout << answer << endl;

    return 0;
}