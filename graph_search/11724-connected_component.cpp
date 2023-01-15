#include <iostream>
#include <map>
#include <vector>
#include <stack>
using namespace std;

map<int, vector<int>> points;
bool visited[1001];

int DFS() {
    int result = 0;
    stack<int> s;
    
    for (auto it : points) {
        if (visited[it.first])
            continue;

        s.push(it.first);
        visited[it.first] = true;

        while (!s.empty()) {
            int current = s.top();
            s.pop();
            
            for (auto it2 : points[current]) {
                if (!visited[it2]){
                    s.push(it2);
                    visited[it2] = true;
                }
            }
        }
        result++;
    }
    return result;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        points[p1].push_back(p2);
        points[p2].push_back(p1);
    }

    for (int i =1; i < N+1; i++) {
        points[i].push_back(i);
    }

    cout << DFS() << endl;
}