#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
    priority_queue<int> connected;
};

Node nodeList[1001];
bool visited[1001];


int main() {
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        nodeList[p1].connected.push(p2);
        nodeList[p2].connected.push(p1);
    }

    //DFS
    stack<int> DFS;
    priority_queue<int> tempPQ;
    
    cout << V << " ";
    visited[V] = true;

    tempPQ = nodeList[V].connected;
    while (!tempPQ.empty()) {
        DFS.push(tempPQ.top());
        tempPQ.pop();
    }

    while (!DFS.empty()) {
        int newNode = DFS.top();
        DFS.pop();
        if (!visited[newNode]) {
            cout << newNode << " ";
            visited[newNode] = true;

            tempPQ = nodeList[newNode].connected;
            while (!tempPQ.empty()) {
                DFS.push(tempPQ.top());
                tempPQ.pop();
            }
        }
    }

    //reset
    cout << endl;
    fill(visited, visited + 1001, false);

    //BFS
    queue<int> BFS;
    vector<int> tempVec;

    cout << V << " ";
    visited[V] = true;

    tempPQ = nodeList[V].connected;
    while (!tempPQ.empty()) {
        tempVec.push_back(tempPQ.top());
        tempPQ.pop();
    }
    for (int i = tempVec.size() - 1; i >= 0; i--) {
        BFS.push(tempVec[i]);
    }
    tempVec.clear();

    while (!BFS.empty()) {
        int newNode = BFS.front();
        BFS.pop();
        
        if (!visited[newNode]) {
            visited[newNode] = true;
            cout << newNode << " ";
            
            tempPQ = nodeList[newNode].connected;
            while (!tempPQ.empty()) {
                tempVec.push_back(tempPQ.top());
                tempPQ.pop();
            }
            for (int i = tempVec.size() - 1; i >= 0; i--) {
                BFS.push(tempVec[i]);
            }
            tempVec.clear();
        }
    }

    cout << endl;
    return 0;
}