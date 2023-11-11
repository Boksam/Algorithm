#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> nums;
vector<int> ans;

void back_tracking(int l) {
    if (l == m) {
        for (auto n : ans)
            cout << n << " ";
        cout << '\n';
        return;
    }

    int last = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] != last && (ans.empty() || ans.back() <= nums[i])) {
            ans.push_back(nums[i]);
            last = nums[i];

            back_tracking(l + 1);

            ans.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    nums.resize(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    back_tracking(0);
}