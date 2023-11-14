#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    if (input == 0) {
      if (pq.size() == 0) {
        cout << 0 << '\n'; 
        continue;
      }
      cout << pq.top() << '\n';
      pq.pop();
    }
    else {
      pq.push(input);
    }
  }
  return 0;
}