#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bellmanFord(int start, int N, vector<vector<int>> &v);


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int TC;
    cin >> TC;

    for (int i = 0; i < TC; i++) {
        int N, M, W;
        cin >> N >> M >> W;

        vector<vector<int>> v;
        
        for (int j = 0; j < M; j++) {
            int p1, p2, cost;
            cin >> p1 >> p2 >> cost;
            v.push_back({p1, p2, cost});
            v.push_back({p2, p1, cost});
        }
        for (int j = 0; j < W; j++) {
            vector<int> warmHole(3);
            cin >> warmHole[0] >> warmHole[1] >> warmHole[2];
            warmHole[2] *= -1;
            v.push_back(warmHole);
        }

        if (bellmanFord(1, N, v))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}


bool bellmanFord(int start, int N, vector<vector<int>> &v) {
    vector<int> distances(N+1, 1e9);
    
    distances[start] = 0;

    for (int i = 0; i < N; i++) {
        for (auto road : v) {
            int s = road[0];
            int e = road[1];
            int c = road[2];

            if (distances[e] > distances[s] + c) {
                if (i == N-1) return true;

                distances[e] = distances[s] + c;
            }
        }
    }

    return false;
}