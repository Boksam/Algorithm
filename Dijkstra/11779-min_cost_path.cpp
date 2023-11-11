#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int N, M;
int s_c, e_c;

map<int, vector<pair<int, int>>> adj;
vector<int> cost;
vector<int> paths;
vector<int> ansPath;

void getPath(int city) {
    if (city == s_c) {
        ansPath.push_back(s_c);
        return;
    }
    
    getPath(paths[city]);
    ansPath.push_back(city);
}

void dijkstra() {
    
    fill(cost.begin(), cost.end(), 1e9);

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

    pq.push({0, s_c});

    while (!pq.empty()) {
        int curr_city = pq.top().second;
        int curr_cost = pq.top().first;
        pq.pop();

        if (cost[curr_city] < curr_cost) continue;

        for (auto it : adj[curr_city]) {
            int next_city = it.second;
            int next_cost = it.first;

            if (cost[next_city] > curr_cost + next_cost) {
                cost[next_city] = curr_cost + next_cost;
                pq.push({cost[next_city], next_city});
                paths[next_city] = curr_city;
            }
        }
    }

    getPath(e_c);

    cout << cost[e_c] << '\n';
    cout << ansPath.size() << '\n';
    for (auto idx : ansPath)
        cout << idx << " ";
    cout << '\n';
}

int main() {
    cin >> N >> M;

    cost.resize(N + 1);
    paths.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        adj[s].push_back({c, e});
    }

    cin >> s_c >> e_c;

    dijkstra();
}