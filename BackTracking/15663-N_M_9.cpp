#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;
vector<bool> used;
vector<int> ans;

void back_tracking(int n) {
    if (n == M) {
        for (auto n : ans)
            cout << n << ' ';
        cout << '\n';
        return;
    }

    int last = -1;
    for (int i = 0; i < N; i++) {
        if (!used[i] && nums[i] != last) {
            last = nums[i];
            used[i] = true;
            ans.push_back(nums[i]);

            back_tracking(n + 1);

            used[i] = false;
            ans.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;
    
    nums.resize(N);
    used.resize(N);

    for (int i = 0; i < N; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    back_tracking(0);
}