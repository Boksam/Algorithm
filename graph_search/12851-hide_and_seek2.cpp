#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

int N, K;
unordered_set<int> us;

void BFS() {
    int time = 0, count = 0;
    bool found = false;
    queue<int> q;

    q.push(N);

    while (true) {
        queue<int> tmp_q;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            us.insert(curr);

            if (curr == K) {
                found = true;
                count++;
            }
            vector<int> v {curr-1, curr+1, curr*2};
            for (auto pos : v) {
                if (0 <= pos && pos <= 100000) {
                    if (us.find(pos) == us.end()) {
                        tmp_q.push(pos);
                    }
                }
            }
        }
        if (found) {
            cout << time << '\n' << count << '\n';
            return;
        }

        q = tmp_q;
        time++;
    }
}

int main() {
    cin >> N >> K;

    BFS();
}