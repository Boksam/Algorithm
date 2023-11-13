#include <iostream>
#include <map>
using namespace std;

int N, M;
map<int, string> numToString;
map<string, int> stringToNum;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    string pokemon;
    cin >> pokemon;
    numToString[i] = pokemon;
    stringToNum[pokemon] = i;
  }

  for (int i = 0; i < M; i++) {
    string question;
    cin >> question;
    if ('0' <= question[0] && question[0] <= '9') {
      cout << numToString[stoi(question)] << '\n';
    }
    else {
      cout << stringToNum[question] << '\n';
    }
  }
  return 0;
}