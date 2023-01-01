#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> meetings;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int begin, end;
        cin >> begin >> end;

        meetings.push_back(make_pair(end, begin));
    }

    sort(meetings.begin(), meetings.end());

    int time = 0, count = 0;
    for (auto it : meetings) {
        if (time <= it.second) {
            time = it.first;
            count++;
        }
    }

    cout << count << endl;
}