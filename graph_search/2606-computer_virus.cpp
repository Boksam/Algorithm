#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

map<int, vector<int>> computers;
bool isVisited[101];

int DFS(int begin) {
    stack<int> s;
    s.push(begin);
    
    isVisited[begin] = true;
    int count = 0;

    while (!s.empty()) {
        int newC = s.top();
        s.pop();

        for (auto it : computers[newC]) {
            if (!isVisited[it]) {
                isVisited[it] = true;
                s.push(it);
                count++;
            }
        }
    }

    return count;
}

int main() {
    int compNum, connectNum;
    cin >> compNum >> connectNum;

    for (int i = 0; i < connectNum; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        computers[c1].push_back(c2);
        computers[c2].push_back(c1);
    }


    cout << DFS(1) << endl;
}