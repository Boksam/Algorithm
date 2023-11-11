#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int INF = 1e9;

int n, m, r;
vector<int> items;
map<int, vector<pair<int, int>>> adj;
vector<vector<int>> dist;


void floyd_warshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}


int main() {
    cin >> n >> m >> r;

    items.resize(n + 1);
    dist.resize(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
        cin >> items[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    int s, e, c;
    for (int i = 0; i < r; i++) {
        cin >> s >> e >> c;
        dist[s][e] = c;
        dist[e][s] = c;
    }

    floyd_warshall();

    int best = 0;
    for (int i = 1; i <= n; i++) {
        int curr_best = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] <= m)
                curr_best += items[j];
        }
        best = max(best, curr_best);
    }

    cout << best << endl;
}