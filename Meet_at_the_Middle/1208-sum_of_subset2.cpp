#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N, S, result = 0;
vector<int> nums;
map<int, int> map_left;
map<int, int> map_right;


void pre_left(int cnt, int sm) {
    if (cnt == N / 2) {
        map_left[sm]++;
        return;
    }
    pre_left(cnt + 1, sm + nums[cnt]);
    pre_left(cnt + 1, sm);
}


void pre_right(int cnt, int sm) {
    if (cnt == N) {
        result += map_left[S - sm];
        return;
    }
    pre_right(cnt + 1, sm + nums[cnt]);
    pre_right(cnt + 1, sm);
}


int main() {
    cin >> N >> S;
    nums.resize(N);


    for (int i = 0; i < N; i++)
        cin >> nums[i];

    pre_left(0, 0);
    pre_right(N / 2, 0);

    if (S == 0) cout << result - 1 << endl;
    else cout << result << endl;

    return 0;
}