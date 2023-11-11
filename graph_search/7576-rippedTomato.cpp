#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;
vector<vector<int>> box;
vector<vector<int>> timeSpent;
queue<pair<int, int>> q;
int ripped = 0, unripped = 0;

int BFS() {
    if (ripped == 0)
        return -1;
    if (unripped == 0)
        return 0;

    int currTime = 0, answer = 0;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        int ys[4] = {y+1, y-1, y, y};
        int xs[4] = {x, x, x-1, x+1};
        for (int i = 0; i < 4; i++) {
            if (ys[i] < 0 || ys[i] >= N || xs[i] < 0 || xs[i] >= M)
                continue;
            if (box[ys[i]][xs[i]] == 0) {
                q.push(make_pair(ys[i], xs[i]));
                box[ys[i]][xs[i]] = 1;
                timeSpent[ys[i]][xs[i]] = timeSpent[y][x] + 1;
                answer = max(answer, timeSpent[ys[i]][xs[i]]);
                unripped--;
                ripped++;
            }
        }
        currTime++;
    }

    if (unripped != 0)
        return -1;
    else
        return answer;
}

int main() {
    cin >> M >> N;
    box.resize(N, vector<int>(M));
    timeSpent.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push(make_pair(i, j));
                timeSpent[i][j] = 0;
                ripped++;
            }
            if (box[i][j] == 0)
                unripped++;
        }

    cout << BFS() << endl;
}