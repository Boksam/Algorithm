#include <iostream>
#include <queue>
using namespace std;

bool isVisited[100001];
queue<pair<int, int>> q;

int BFS(int k) {
    while (!q.empty()) {
        int newP = q.front().first;
        int newT = q.front().second;
        q.pop();

        if (newP == k)
            return newT;
        
        int checkPs[3] = {newP - 1, newP + 1, newP * 2};
        for (int i = 0; i < 3; i++) {
            int checkP = checkPs[i];
            if (checkP < 0 || checkP > 100000)
                continue;
            
            if (!isVisited[checkP]) {
                isVisited[checkP] = true;
                q.push(make_pair(checkP, newT + 1));
            }
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    
    q.push(make_pair(N, 0));
    
    cout << BFS(K) << endl;
}