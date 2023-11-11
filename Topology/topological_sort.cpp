#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int N, K;
vector<vector<int>> adjacent;
vector<int> inDegree;


vector<int> kahn() {
    vector<int> answer;
    queue<int> q;

    for (int i = 1; i <= N; i++)
        for (auto nextNode : adjacent[i])
            inDegree[nextNode]++;

    for (int i = 1; i <= N; i++)
        if (inDegree[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        answer.push_back(curr);

        for (auto n : adjacent[curr]) {
            inDegree[n]--;
            if (inDegree[n] == 0)
                q.push(n);
        }
    }

    return answer;
}


int main() {
    cin >> N >> K;
    adjacent.resize(N + 1);
    inDegree.resize(N + 1);

    for (int i = 0; i < K; i++) {
        int start, end;
        cin >> start >> end;
        adjacent[start].push_back(end);
    }

    vector<int> ans = kahn();

    for (auto n : ans)
        cout << n << " ";
    cout << endl;
    return 0;
}