#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 1e9;

int N, K;
vector<int> best(100001);

int bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, N});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if (pos == K) {
            return cost;
        }

        if (cost < best[pos]) {
            best[pos] = cost;

            vector<pair<int, int>> neighbors = 
                {{cost + 1, pos - 1}, {cost + 1, pos + 1}, {cost, pos * 2}};
            
            for (pair<int, int> neighbor : neighbors) {
                if (neighbor.second < 0 || 100000 < neighbor.second)
                    continue;
                
                pq.push(neighbor);
            }
        }
    }
}

int main() {
    cin >> N >> K;

    fill(best.begin(), best.end(), INF);

    cout << bfs() << endl;
}