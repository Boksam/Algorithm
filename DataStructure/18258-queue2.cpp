#include <iostream>
#include <deque>
using namespace std;

int N, n;
string command;
deque<int> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> command;

    if (command == "push") {
      cin >> n;
      q.push_back(n);
    }
    else if (command == "pop") {
      if (!q.empty()) {
        cout << q.front() << '\n';
        q.pop_front();
      }
      else
        cout << -1 << '\n';
    }
    else if (command == "size") {
      cout << q.size() << '\n';
    }
    else if (command == "empty") {
      if (q.empty()) cout << 1 << '\n';
      else cout << 0 << '\n';
    }
    else if (command == "front") {
      if (!q.empty()) cout << q.front() << '\n';
      else cout << -1 << '\n';
    }
    else if (command == "back") {
      if (!q.empty()) cout << q.back() << '\n';
      else cout << -1 << '\n';
    }
  }
}