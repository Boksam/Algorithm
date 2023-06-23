#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int T, N, K, W;
vector<int> cost;
vector<int> dp;
vector<vector<int>> adj;
vector<int> seq;


void getSequence() {
    vector<int> inDegree(N + 1);
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        for (auto n : adj[i]) {
            inDegree[n]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        seq.push_back(curr);
        for (auto n : adj[curr]) {
            inDegree[n]--;
            if (inDegree[n] == 0)
                q.push(n);
        }
    }
}

int main() {
    cin >> T;

    while (T--) {
        cin >> N >> K;
        cost.resize(N + 1);
        adj.resize(N + 1);
        dp.resize(N + 1);

        for (int i = 1; i <= N; i++)
            cin >> cost[i];

        for (int i = 0 ; i < K; i++) {
            int s, e;
            cin >> s >> e;
            adj[s].push_back(e);
        }

        cin >> W;

        getSequence();
        
        for (auto n : seq) {
            dp[n] += cost[n];
            for (auto next : adj[n]) {
                if (dp[n] > dp[next])
                    dp[next] = dp[n];
            }
        }

        cout << dp[W] << endl;

        cost.clear();
        adj.clear();
        dp.clear();
        seq.clear();
    }
}