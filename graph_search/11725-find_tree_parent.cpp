#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

int N;
map <int, vector<int>> m;


void dfs() {
    vector<bool> visited(N+1);
    vector<int> answer(N+1);
    stack<int> s;

    s.push(1);
    visited[1] = true;

    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        visited[curr] = true;

        for (int child : m[curr]) {
            if (!visited[child]) {
                answer[child] = curr;
                s.push(child);
            }
        }
    }
    
    for (int i = 2; i <= N; i++) {
        cout << answer[i] << '\n';
    }
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N-1; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        m[p1].push_back(p2);
        m[p2].push_back(p1);
    }

    dfs();
}