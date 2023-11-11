#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int result = 1e9, store_cnt = 0, house_cnt = 0;
vector<vector<int>> grid;
vector<pair<int, int>> houses;
vector<pair<int, int>> stores;
vector<bool> open;

int calc_dist() {
    int dist = 0;

    for (auto house : houses) {
        int min_dist = 1e9;
        for (int i = 0; i < store_cnt; i++) {
            if (open[i]) {
                int new_dist = abs(house.first - stores[i].first) + abs(house.second - stores[i].second);
                min_dist = min(min_dist, new_dist);
            }
        }
        dist += min_dist;
    }

    return dist;
}


void back_tracking(int l, int cnt) {
    if (store_cnt - cnt <= m) {

        result = min(result, calc_dist()); 
        return;
    }

    for (int i = l; i < store_cnt; i++) {
        if (open[i]) {
            open[i] = false;
        
            back_tracking(i, cnt + 1);

            open[i] = true;
        }
    }
}


int main() {
    cin >> n >> m;

    grid.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                houses.push_back({i, j});
                house_cnt++;
            }
            else if (grid[i][j] == 2) {
                stores.push_back({i, j});
                store_cnt++;
            }
                
        }
    }

    open.resize(stores.size());
    fill(open.begin(), open.end(), true);
        
    back_tracking(0, 0);
    
    cout << result << endl;
    return 0;
}