#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

map<int, bool> isPrinted;
priority_queue<int, vector<int>, greater<int>> myPQ;


int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int query;
        cin >> query;

        if (query == 0) {
            if (myPQ.empty())
                cout << "0\n";
            else {
                cout << myPQ.top() << '\n';
                myPQ.pop();
            }
        }
        else {
            myPQ.push(query);
        }
    }
}