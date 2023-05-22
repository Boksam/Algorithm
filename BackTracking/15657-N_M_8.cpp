#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;
vector<int> ans;

void back_tracking(int n) {
    if (n == M) {
        for (auto n : ans)
            cout << n << " ";
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (ans.size() == 0 || nums[i] >= ans.back()) {
            ans.push_back(nums[i]);
            back_tracking(n + 1);
            ans.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;

    nums.resize(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    back_tracking(0);
}