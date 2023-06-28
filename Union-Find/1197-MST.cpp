#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int v, e, result = 0;
vector<int> root;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;


int unionFind(int x) {
    if (root[x] == x) return x;
    else return root[x] = unionFind(root[x]);
}


void uni(int x, int y) {
    x = unionFind(x);
    y = unionFind(y);
    root[y] = x;
}


bool isSameParent(int p1, int p2) {
    p1 = unionFind(p1);
    p2 = unionFind(p2);
    return p1 == p2;
}


int main() {
    cin >> v >> e;
    root.resize(v + 1);

    for (int i = 1; i <= v; i++)
        root[i] = i;

    for (int i = 0; i < e; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        pq.push({c, {s, e}});
    }

    while (!pq.empty()) {
        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();

        if (!isSameParent(curr.second.first, curr.second.second)) {
            result += curr.first;
            uni(curr.second.first, curr.second.second);
        }
    }

    cout << result << endl;
    return 0;
}