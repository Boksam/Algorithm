#include <iostream>
#include <vector>
using namespace std;

int first = 0, second = 0, answer = 0;
string s;

int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      first += 1;
    }
    else if (s[i-1] == '(' && s[i] == ')'){
      first -= 1;
      answer += first * 2 + second;
      second += first;
      first = 0;
    }
    else {
      second -= 1;
    }
  }
  cout << answer << endl;
  return 0;
}