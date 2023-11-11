#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

long long a, b;

int bfs(int a, int b) {
    queue<long long> q;
    unordered_set<long long> us;
    long long result = 0;
    q.push(a);
    us.insert(a);

    while (!q.empty()) {
        queue<long long> tmp_q;

        while (!q.empty()) {
            long long curr = q.front();
            q.pop();

            if (curr == b) return result + 1;

            long long n1 = curr * 2;
            long long n2 = curr * 10 + 1;
            
            if (n1 <= b && us.count(n1) == 0) {
                tmp_q.push(n1);
                us.insert(n1);
            }
            if (n2 <= b && us.count(n2) == 0) {
                tmp_q.push(n2);
                us.insert(n2);
            }
        }
        q = tmp_q;
        result++;
    }

    return -1;
}

int main() {
    cin >> a >> b;

    cout << bfs(a, b) << endl;
}