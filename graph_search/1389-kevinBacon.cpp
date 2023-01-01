#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Person {
public:
    vector<int> friends;
};

int N, M;
vector<Person> people;

int kevinBacon(int p) {
    vector<bool> visited(N + 1);
    visited[p] = true;

    int layer = 1;
    int visitCount = 0;
    int KB = 0;
    
    queue<int> nowVisit;
    queue<int> nextVisit;
    
    for (auto it : people[p].friends)
        nextVisit.push(it);
    
    while (visitCount < N - 1) {
        nowVisit = nextVisit;
        while (!nowVisit.empty()) {
            int newP = nowVisit.front();
            nowVisit.pop();
            
            if (!visited[newP]) {
                visited[newP] = true;
                KB += layer;
                visitCount++;
            }
            for (auto it : people[newP].friends)
                nextVisit.push(it);
        }
        layer++;
    }
    return KB;
}

int main() {
    cin >> N >> M;
    people.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int f1, f2;
        cin >> f1 >> f2;
        people[f1].friends.push_back(f2);
        people[f2].friends.push_back(f1);
    }

    int minKB = 10000000, minPos = -1;
    for (int i = 1; i <= N; i++) {
        int newKB = kevinBacon(i);
        if (newKB < minKB) {
            minPos = i;
            minKB = newKB;
        }
    }

    cout << minPos << endl;
}