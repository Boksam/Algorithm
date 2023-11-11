#include <iostream>
#include <vector>
using namespace std;

bool isBroken[10] = { false, };
int N, M, optimalNum = 10000000, minDiff = 99999900;


bool check(int num) {
    string numToStr = to_string(num);
    for (char c : numToStr) {
        if (isBroken[c - '0'])
            return false;
    }
    return true;
}


int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        isBroken[temp] = true;
    }


    int answer = abs(N - 100);
    for (int i = 0; i < 1000000; i++) {
        if (check(i)) {
            int newMin = abs(N - i) + to_string(i).length();
            answer = min(answer, newMin);
        }
    }

    cout << answer << endl;
    return 0;
}