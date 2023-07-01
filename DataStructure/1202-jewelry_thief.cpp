#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 300001

int n, k;
long long result = 0;

pair<int, int> jewelry[MAX];
int bag[MAX];

priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> jewelry[i].first >> jewelry[i].second;

    for (int i = 0; i < k; i++)
        cin >> bag[i];

    sort(jewelry, jewelry + n);
    sort(bag, bag + k);

    int idx = 0;
    for (int i = 0; i < k; i++) {
        while (idx < n && bag[i] >= jewelry[idx].first)
            pq.push(jewelry[idx++].second);
            
        if (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result << endl;
    return 0;
}